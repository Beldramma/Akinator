#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct{
  int numero_question;
  int chiffre_reponse;
}Reponse;

typedef struct personnage{
  char nom_perso[20];
  int note_perso;
  int num;
  Reponse *liste_reponses;
  struct personnage *perso_suiv;
  struct personnage *perso_prec;
}Personnage;

typedef struct {
  int nb_perso;
  Personnage *tete;
}Liste_Perso;


/* LEO : ajouter les structures pour les questions */

/* Definition des differentes fonctions utilisees */
void init_liste(Liste_Perso *ptr_liste);
Personnage *creer_personnage(char* nom_perso,int note_perso);
void ajout_personnage(Liste_Perso *ptr_liste,Personnage *ptr_perso);
void init_rang(Liste_Perso *liste_perso);
int note_personnage(Personnage *perso, int choix,int num);
void maj_note_perso(Liste_Perso* liste_perso,int choix, int num);
void supprimer_perso(Liste_Perso *ptr_liste, int rang);
void resultats(Liste_Perso liste_perso);
/*-----*/
int note_question(int nb_qst, Liste_Perso *liste_perso);
void pose_question(Liste_Perso liste_perso) ;

/* ajouter les autres fonctions */


/* Initialisation des listes et structures */

void init_liste(Liste_Perso *ptr_liste)
{	ptr_liste->nb_perso=0;}


Personnage *creer_personnage(char *nom_perso,int note_perso)
{
  Personnage *perso;
  perso=(Personnage*)malloc(sizeof(Personnage));
  strcpy(perso->nom_perso,nom_perso);
  perso->note_perso=note_perso;
  perso->perso_suiv=NULL;
  perso->perso_prec=NULL;
  return perso;
}

void init_rang(Liste_Perso liste_perso){
Personnage *ptr_cour;
ptr_cour=liste_perso->tete;
for(i=0;i<liste_perso->nb_perso;i++){
	ptr_cour->num=i;
	ptr_cour=ptr_cour->perso_suiv;
}}
	

void ajout_personnage(Liste_Perso *ptr_liste,Personnage *ptr_perso)
{
  Personnage *ptr;
  if (ptr_liste->tete==NULL)
    {ptr_liste->tete=ptr_perso;}
  else{
    ptr=ptr_liste->tete;
    while (ptr-> perso_suiv != NULL)
      {ptr=ptr-> perso_suiv;}
    ptr->perso_suiv=ptr_perso;}
  ptr_liste->nb_perso ++;}



/* Programme principal */

int main(){
  jeu();

  /*
  int choix;
  choix=0;
  while(choix==0){
    jeu();
    printf("Souhaitez-vous rejouer ? Oui(0)  Non(1)\n");
    scanf("%d",&choix);}  */
  
  return 0;}


/* Interface terminal */

void jeu(){
  
  int x,i,choix,q;
  char* nom,quest;
  
  printf("\nVous allez jouer au jeu du devin.\nPour cela, vous devez penser tres fort a une personne.\n");
  printf("Appuyez sur une touche lorsque vous etes prets!\n");
  scanf("%d",&x);
  printf("\nSuper ! Nous allons pouvoir commencer ...\n\n");
  printf("Je vais tenter de deviner votre personnage en vous posant 20 questions. C'est parti !\n");
  
  /* Appel des differentes fonctions crees */
  for(i=1;i<=20;i++){
    
    printf("\nQuestion %d : ",i);
    /* q=pose_question(personnages);*/
    printf("\n");
    printf("Votre reponse :\nSurement (1)  Probablement oui (2)  Je ne sais pas (3)  Probablement non (4) Surement pas (5)\n");
    scanf("%d",&choix);
    /* maj_note_perso(personnages,choix,q);*/
  }
  printf("\nOk je pense que j'ai trouvé ! Votre personnage est ... ");
  /* resultat(personnages); */
  printf("Est-ce la bonne réponse ? Oui(0)  Non(1)\n");
  scanf("%d",&x);

  if(x==0){
    printf("Waou ! Je suis tellement fort !\n");
    /* mise a jour des donnees du personnage trouvé */
  }
  else if(x==1){
    printf("Oups ... je dois encore m'entraîner un peu ...\nA quel personnage pensiez vous ?\n");
    scanf("%s",&nom);
    /* new_personnage(population.txt,nom,rep); */
    printf("Quelle question aurait-pu permettre de trouver votre personnage ?\n");
    scanf("%s",&quest);
    /* creer_question(questions.txt,quest); */
  }}


		     
/*FONCTIONS */      

int note_personnage(Personnage *perso, int choix,int num) {  /*recupere la réponse de l'utilisateur et le perso avec lequel on compare*/
  int a, m, note=0;
  a=perso->liste_reponses[num].chiffre_reponse /* attention au décalage avec le i, ne pas commencer les numeros des questions à 1 mais à 0 */
  m=choix-a; /* différence entre la valeur souhaitée et la valeur renseignée */
  m=fabs(m);
  if(m==1){
      note++;}
  else if{(m==2) {
    note--;}
  else if{(m==3){
	  note=note-2;}
  else if{(m==4){
	  note=note-3;}
  else {note=note+3;}}}}}
  return note;}
    
   

void maj_note_perso(Liste_Perso* liste_perso,int choix, int num) {
  Personnage* ptr_cour;
  int i;
  ptr_cour=liste_perso->tete;
  for (i=0; i<liste_perso->nb_perso; i++) {
    ptr_cour->note_perso=note_personnage(ptr_cour,choix,num);

	  /* suppresion des personnages avec note <-10 */
    if ((ptr_cour->note_perso)<(-10)){
	    supprimer_perso(liste_perso,ptr_cour->num);}   
	  
    ptr_cour=ptr_cour->perso_suiv;}}

	
void supprimer_perso(Liste_Perso *ptr_liste, int rang){
	Noeud *ptr_cour, *ptr_prec;
	int i;
	
	if(rang==0){
		ptr_cour=ptr_liste->tete;
		ptr_liste->tete=ptr_cour->perso_suiv;
		ptr_liste->tete->perso_prec=NULL;
		free(ptr_cour);}
	else {
		i=1;
		ptr_prec=ptr_liste->tete;
		while(i != rang){
			i++;
			ptr_prec=ptr_prec->perso_suiv;}
		ptr_cour=ptr_prec->perso_suiv;
		ptr_prec->perso_suiv=ptr_cour->perso_suiv; 
		ptr_cour->perso_suiv->perso_prec=ptr_prec;
		free(ptr_cour);}}
		     
 

 /* void resultats(Personnages personnages) : entrée :  liste chainée personnages     sortie : /  fonctionnement : affiche le résultat en fonction des notes des personnages (compare les notes).   */
    
void resultats(Liste_Perso liste_perso) {
  Personnage* ptr_cour;
  int i;
  char* s;
  
  ptr_cour=liste_perso->tete;
  note=ptr_cour->note_perso;
  s=ptr_cour->nom_perso;
  for (i=0; i<liste_perso->nb_perso; i++) {
    ptr_cour=ptr_cour->perso_suiv;
    if (note<ptr_cour->note_perso) {
      note=ptr_cour->note_perso;
      s=ptr_cour->nom_perso;}}
  printf("%s", s);
}



