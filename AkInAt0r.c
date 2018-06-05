#include <stdio.h>
#include <stdlib.h>

typedef struct reponse {
	int numero_question;
	int chiffre_reponse;
}Reponse;

typedef struct personnage {
	char *nom_perso;
	int note_perso;
	Reponse *liste_reponse;
	struct personnage perso_suiv;
	struct personnage perso_prec;
} Personnage;

typedef struct liste_perso {
	int nb_perso;
	Personnage *tete;
} Liste_Perso;

void init_liste(Liste_Perso *ptr_liste);
Personnage *creer_personnage(char* nom_perso,int note_perso);
void ajout_personnage(Liste_Perso *ptr_liste,Personnage *ptr_perso)

void init_liste(Liste_Perso *ptr_liste)
{
	ptr_liste->nb_perso=0;
}


Personnage *creer_personnage(char *nom_perso,int note_perso)
{
	Personnage *perso;
	perso=(Personnage*)malloc(sizeof(Personnage));
	perso->nom_perso=nom_perso;
	perso->note_perso=note_perso;
	perso->perso_suiv=NULL;
	perso->perso_prec=NULL;
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
