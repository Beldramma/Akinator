#include <stdio.h>
#include <stdlib.h>
#define NB_PERSO 8

int cpt=0;


typedef struct personnage {
	char *nom_perso;
	int note_perso;
	int *liste_reponse;
	struct personnage *perso_suiv;
} Personnage;

typedef struct liste_perso {
	int nb_perso;
	Personnage *tete;
} Liste_Perso;




Personnage *creer_personnage(char* nom_perso);
void ajout_personnage(Liste_Perso *ptr_liste,Personnage *ptr_perso);

Liste_Perso *init_liste()
{
	Liste_Perso *ptr_liste;
	
	ptr_liste=(Liste_Perso*)malloc(sizeof(Liste_Perso));
	ptr_liste->nb_perso=0;
	ptr_liste->tete=NULL;
	
	return ptr_liste;
}

/*void afficher_element(Personnage *ptr)
{
	if (ptr != NULL)
	{
		printf("%s\n",ptr->nom_perso);
		printf("%d\n",ptr->note_perso);
		afficher_element(ptr->perso_suiv);
	}
}*/

void afficher_element(Liste_Perso liste)
{
	Personnage *ptr_perso;
	
	for(ptr_perso=liste.tete;ptr_perso != NULL;ptr_perso=ptr_perso->perso_suiv)
	{
		printf("%s\n",ptr_perso->nom_perso);
	}
}

Personnage *creer_personnage(char *nom_perso)
{
	Personnage *perso;
	perso=(Personnage*)malloc(sizeof(Personnage));
	perso->nom_perso=nom_perso;
	perso->note_perso=1;
	perso->liste_reponse=(int*)malloc(5*sizeof(int));
	perso->perso_suiv=NULL;
	return perso;
}

void ajout_personnage(Liste_Perso *ptr_liste,Personnage *ptr_perso)
{
	Personnage *ptr;
	cpt++;
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
	printf("nom ajout:%s\n",ptr_liste->tete->nom_perso);
}

Liste_Perso* recuperation_nom_reponse()
{
	Liste_Perso *ptr_liste;
	ptr_liste=init_liste();
	Personnage *perso;
	char nom_perso[40];
	/*nom_perso=(char*)malloc(30*sizeof(char));*/
	int cp=0,i=0,j=0;
	char c;
	FILE* flux;
	flux=fopen("Population.txt","r");
	if (flux==NULL)
	{
		printf("Pas de fichiers\n");
		return NULL;
	}
	while(/*(feof(flux)==0)||*/(i==0)&&(j<9))
	{
		j++;
		fgets(nom_perso,sizeof(nom_perso),flux);
		perso=creer_personnage(nom_perso);
		ajout_personnage(ptr_liste,perso);
		/*puts(perso->nom_perso);*/
		printf("%s\n",perso->nom_perso);
		cp=0;
		while (cp<8 ) 
		{
			c=fgetc(flux);
			
			if ((c!=' ')&&(c!='\n'))
			{
				perso->liste_reponse[cp]=c;
				cp++;
			}
		}
		printf("cpt=%d\n",cpt);
		
		while(((c=fgetc(flux))!='\n')&&(i==0))
		{
			printf ("c=%c\n",c);
			if(c==EOF)
			{
				i=1;
			}
		}
	
	
}
	printf("OK\n");
	
	fclose(flux);
	return ptr_liste;
}


int main()
{
	Liste_Perso *ptr_liste;
	ptr_liste=recuperation_nom_reponse();
	printf("nombre_perso=%d\n",ptr_liste->nb_perso);
	printf("nom:%s\n",ptr_liste->tete->nom_perso);
	afficher_element(*ptr_liste);
	return 0;
}
