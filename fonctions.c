#include "fonctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int nb_perso=0;
int nb_reponse=0;
int nb_question=0;

Liste_Perso *init_liste()
{
	Liste_Perso *ptr_liste;
	
	ptr_liste=(Liste_Perso*)malloc(sizeof(Liste_Perso));
	ptr_liste->nb_perso=0;
	ptr_liste->tete=NULL;
	
	return ptr_liste;
}


void afficher_element(Liste_Perso liste)
{
	Personnage *ptr_perso;
	int i;
	
	for(ptr_perso=liste.tete;ptr_perso != NULL;ptr_perso=ptr_perso->perso_suiv)
	{
		printf("%s\n",ptr_perso->nom_perso);
		for(i=0;i<nb_reponse;i++)
		{
			printf("%c\t",ptr_perso->liste_reponse[i]);
		}
		printf("\n");
	}
}

Personnage *creer_personnage(char *nom_perso)
{
	Personnage *perso;
	perso=(Personnage*)malloc(sizeof(Personnage));
	int L=strlen(nom_perso);
	perso->nom_perso=(char*)malloc((L+1)*sizeof(char));
	strcpy(perso->nom_perso,nom_perso);
	perso->note_perso=1;
	perso->liste_reponse=(int*)malloc(nb_reponse*sizeof(int));
	perso->perso_suiv=NULL;
	return perso;
}

void ajout_personnage(Liste_Perso *ptr_liste,Personnage *ptr_perso)
{
	Personnage *ptr;
	if (ptr_liste->tete==NULL)
	{
		ptr_liste->tete=ptr_perso;
	}else{
		ptr=ptr_liste->tete;
		while (ptr->perso_suiv != NULL)
		{
			ptr=ptr->perso_suiv;
		}
		ptr->perso_suiv=ptr_perso;
	
	}
	ptr_liste->nb_perso ++;
}

Liste_Perso* recuperation_nom_reponse()
{
	Liste_Perso *ptr_liste;
	ptr_liste=init_liste();
	Personnage *perso;
	char nom_perso[40];
	/*nom_perso=(char*)malloc(30*sizeof(char));*/
	int cp=0,i=0,j=0;
	int c;
	FILE* flux;
	flux=fopen("Population.txt","r");
	if (flux==NULL)
	{
		printf("Pas de fichiers\n");
		return NULL;
	}
	while((c=fgetc(flux))!=EOF)
	{
		if(c=='\n')
		{
			nb_perso++;
		}
	}
	fseek(flux,0,SEEK_SET);
	while((c=fgetc(flux))!='\n');
	while((c=fgetc(flux))!='\n')
	{
		nb_reponse++;
	}
	fseek(flux,0,SEEK_SET);
	nb_reponse=nb_reponse-2;
	nb_reponse=nb_reponse/2;
	nb_perso=nb_perso/2;
	while(/*(feof(flux)==0)||*//*(i==0)&&*/(j<nb_perso))
	{
		j++;
		fgets(nom_perso,40,flux);
		perso=creer_personnage(nom_perso);
		ajout_personnage(ptr_liste,perso);
		/*puts(perso->nom_perso);*/
		cp=0;
		while (cp<nb_reponse ) 
		{
			c=fgetc(flux);
			
			if ((c!=' ')&&(c!='\n'))
			{
				perso->liste_reponse[cp]=(c);
				cp++;
			}
		}
		while(((c=fgetc(flux))!='\n')&&(i==0))
		{
			if(c==EOF)
			{
				i=1;
			}
		}
	
	
	}
	
	fclose(flux);
	return ptr_liste;
}

void init_rang(Liste_Perso *liste_personnage)
{
	int i;
	Personnage *ptr_cour;
	ptr_cour=liste_personnage->tete;
	for(i=0;i<liste_personnage->nb_perso;i++){
		ptr_cour->num=i;
		ptr_cour=ptr_cour->perso_suiv;
	}
}

void ecriture_fichier(Personnage *P)
{
	FILE *flux;
	int i;
	int c;
	flux=fopen("Population.txt","r+");
	if (flux==NULL)
	{
		printf("Pas de fichiers\n");
		return;
	}

	fseek(flux,0,SEEK_END);

	fputs(P->nom_perso,flux);
	fputc('\n',flux);
	for(i=0;i<nb_reponse;i++)
	{
		c=P->liste_reponse[i];
		printf("%d\t",c);
		fputc(48+c,flux);
		fputc(' ',flux);
	}
	printf("\n");
	fputc('-',flux);
	fputc('1',flux);
	fputc('\n',flux);
	fclose(flux);
}

void question(Question* l)
{
	FILE* flux;
	flux=fopen("Questions.txt","r");
	char c;

	while((c=fgetc(flux))!=EOF)
	{
		if(c=='\n')
		{
			nb_question++;
		}
	}
	fseek(flux,0,SEEK_SET);
	printf("Nombre de question:%d\n",nb_question);
	int j=0;
	/*l=(Question*)malloc(sizeof(Question));*/
		
	while (/*(feof(flux)==0)&&*/(j<nb_question))
	{
		fgets(l[j].question,70,flux);
		l[j].numero=j;
		l[j].deja_pose=0;
		j++;
	}
	fclose(flux);
}

void creer_question(char *quest)
{
	FILE *flux;
	flux=fopen("Questions.txt","r+");
	if (flux==NULL)
	{
		printf("Pas de fichiers\n");
		return;
	}

	fseek(flux,0,SEEK_END);
	fputc('\n',flux);
	fputs(quest,flux);
	
	fclose(flux);
}

void jeu(Personnage* P, Liste_Perso* liste_perso, Question* liste_question)
{
  char c;
  int x,i,choix,q;
  char quest[80];

  printf("\nVous allez jouer au jeu du devin.\nPour cela, vous devez penser tres fort a une personne.\n");
  printf("Appuyez sur une touche lorsque vous etes prets!\n");
  scanf("%c",&c);
  printf("\nSuper ! Nous allons pouvoir commencer ...\n\n");
  printf("Je vais tenter de deviner votre personnage en vous posant 20 questions. C'est parti !\n");
  
  /* Appel des differentes fonctions crees */
  for(i=1;i<=20;i++){
    
    printf("\nQuestion %d : ",i);
     q=pose_question(*liste_perso,liste_question);
    printf("\n");
    printf("Votre reponse :\nSurement (1)  Probablement oui (2)  Je ne sais pas (3)  Probablement non (4) Surement pas (5)\n");
    /*Rajouter que si différent de 1,2,3,4,5 ne pas accepter*/
    scanf("%d",&choix);
    P->liste_reponse[i]=choix;
     maj_note_perso(liste_perso,choix,q);
  }
  printf("\nOk je pense que j'ai trouvé ! Votre personnage est ... ");
  resultat(liste_perso); 
  printf("Est-ce la bonne réponse ? Oui(0)  Non(1)\n");
  scanf("%d",&x);

  if(x==0){
    printf("Waou ! Je suis tellement fort !\n");
    /* mise a jour des donnees du personnage trouvé */
  }
  else if(x==1){
    printf("Oups ... je dois encore m'entraîner un peu ...\nA quel personnage pensiez vous ?\n");
    scanf("%s",P->nom_perso);
    ecriture_fichier(P);
    printf("Quelle question aurait-pu permettre de trouver votre personnage ?\n");
    scanf("%s",quest);
    creer_question(quest); 
  }
 }

int note_personnage(Personnage *perso, int choix,int num) 
{  /*recupere la réponse de l'utilisateur et le perso avec lequel on compare*/
  int a,m, note=0;
  a=perso->liste_reponse[num]; /* attention au décalage avec le i, ne pas commencer les numeros des questions à 1 mais à 0 */
  m=choix-a; /* différence entre la valeur souhaitée et la valeur renseignée */
  m=fabs(m);
  if(m==1){
      note++;}
  else {if(m==2) {
    note--;}
  else{ 
  	if(m==3){
	  note=note-2;}
  else{ 
  	if(m==4){
	  note=note-3;}
  else {note=note+3;}}}}
  return note;}
  
void maj_note_perso(Liste_Perso* liste_personnage,int choix, int num) 
{
  Personnage* ptr_cour;
  int i;

  ptr_cour=(Personnage*)malloc(sizeof(Personnage));
  ptr_cour=liste_personnage->tete;
  for (i=0; i<liste_personnage->nb_perso; i++) {
 
    ptr_cour->note_perso=note_personnage(ptr_cour,choix,num);

	  /* suppresion des personnages avec note <-10 */
    if ((ptr_cour->note_perso)<(-10)){
	    supprimer_perso(liste_personnage,ptr_cour->num);
	}   
    ptr_cour=ptr_cour->perso_suiv;
}
}
    
void supprimer_perso(Liste_Perso *ptr_liste, int rang)
{
	Personnage *ptr_cour;
	ptr_cour=(Personnage*)malloc(sizeof(Personnage));
	int i;
	
	if(rang==0){
		ptr_cour=ptr_liste->tete;
		ptr_liste->tete=ptr_cour->perso_suiv;
		free(ptr_cour);}
	else {
		i=1;
		while(i != rang){
			i++;
		}
		/*ptr_cour=ptr_prec->perso_suiv;*/
		free(ptr_cour);}
}
		     
 

void resultat(Liste_Perso *liste_personnage) 
{
  Personnage* ptr_cour; 
  int note;
  int i;
  char* s;
  
  ptr_cour=liste_personnage->tete;
  note=ptr_cour->note_perso;
  s=ptr_cour->nom_perso;
  for (i=0; i<liste_personnage->nb_perso; i++) {
    ptr_cour=ptr_cour->perso_suiv;
    if (note<ptr_cour->note_perso) {
      note=ptr_cour->note_perso;
      s=ptr_cour->nom_perso;}}
  printf("%s", s);
}

int note_question(int nb_qst, Liste_Perso liste_personnage) 
{    

  int i,j, Q;
  int reponses[nb_question];
  Personnage* ptr_cour;

	/* initialisation tableau */
	for (i=1; i<=5; i++) {
		reponses[i]=0; }

  /* reponses: tableau tel que l'indice de la case est la réponse et le contenu est le nombre d'occurence de la réponses chez les personnages (incrementée selon les reponses des personnages) */  
  ptr_cour=(Personnage*)malloc(sizeof(Personnage));
  ptr_cour=liste_personnage.tete;
  for(j=1;j<=5;j++)
  {
	  while(ptr_cour!=NULL) {     /*parcourir les personnages*/
  			if(ptr_cour->liste_reponse[nb_qst]==j)
  			{
	      		reponses[j]++;
	      	}
	      ptr_cour=ptr_cour->perso_suiv;
	  }
	  ptr_cour=liste_personnage.tete;
	}
  Q=1;
  for (i=1; i<6; i++) {
    Q=Q*(reponses[i]+1);
  }
  return Q;
}



int pose_question(Liste_Perso liste_personnage, Question *liste_question) 
{ int m;
  int indice_question, i,j=0;
  while(liste_question[j].deja_pose!=0)
  {
  	  m=note_question(j, liste_personnage);
  	  indice_question=j;
  	  j++;
  }

  for (i=j+1; i<nb_question; i++) {
  		if (liste_question[i].deja_pose==0)
  		{
	      if (note_question(i, liste_personnage)>m){
			m=note_question(i, liste_personnage);
			indice_question=i;
			printf("indice :%d\n",indice_question);
		}
      }
  }  	
  /* afficher la question numéro "indice_question" */
  	
  printf("%s", liste_question[indice_question].question);
  liste_question[indice_question].deja_pose=1;
  return indice_question;
}
