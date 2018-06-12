#include <stdio.h>

typedef struct lecture_question {
	int numero;
	char question[70];
	int deja_pose;
}Question;

typedef struct personnage {
	int num;
	char *nom_perso;
	int note_perso;
	int *liste_reponse;
	struct personnage *perso_suiv;
} Personnage;

typedef struct Liste_perso {
	int nb_perso;
	Personnage *tete;
} Liste_Perso;

Liste_Perso *init_liste();
void afficher_element(Liste_Perso liste);
Personnage *creer_personnage(char *nom_perso);
void ajout_personnage(Liste_Perso *ptr_liste,Personnage *ptr_perso);
Liste_Perso* recuperation_nom_reponse();
void question(Question *l);
void init_rang(Liste_Perso *liste_personnage);
void ecriture_fichier(Personnage *P);
void creer_question(char* quest);
void jeu(Personnage* P, Liste_Perso* liste_perso, Question* liste_question);
int note_personnage(Personnage *perso, int choix,int num);
void maj_note_perso(Liste_Perso* liste_personnage,int choix, int num);
void supprimer_perso(Liste_Perso *ptr_liste, int rang);
void resultat(Liste_Perso *liste_personnage);
int note_question(int nb_qst,Liste_Perso liste_personnage);
int pose_question(Liste_Perso liste_personnage, Question *liste_question);

