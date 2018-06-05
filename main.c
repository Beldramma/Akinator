#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Population.txt"
#include "Questions.txt"

typedef struct reponse {
  int numero_question;
  int chiffre_reponse;
}Reponse;

typedef struct personnage {
  char *nom_perso;
  int note_perso;
  Reponse *liste_reponses;
  struct personnage perso_suiv;
  struct personnage perso_prec;
} Personnage;

typedef struct liste_perso {
  int nb_perso;
  Personnage *tete;
} Liste_Perso;


/* Definition des differentes fonctions utilisees */
void init_liste(Liste_Perso *ptr_liste);
Personnage *creer_personnage(char* nom_perso,int note_perso);
void ajout_personnage(Liste_Perso *ptr_liste,Personnage *ptr_perso);
/* ajouter les autres fonctions */


/* Initialisation des listes et structures */

void init_liste(Liste_Perso *ptr_liste)
{	ptr_liste->nb_perso=0;}


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
    }
  else{
    ptr=ptr_liste->tete;
    while (ptr->perso_suiv != NULL)
      {
	ptr=ptr->perso_suiv;
      }
    ptr->perso_suiv=ptr_perso;
  }
  ptr_liste->nb_perso ++;
}



int main(){
  int choix;
  choix=0;
  while(choix==0){
    jeu();
    printf("Souhaitez-vous rejouer ? Oui(0)  Non(1)\n");
    scanf("%d",&choix);}  
  return 0;}


void jeu(){
  
  int x,i,choix,q;
  char* nom,quest;
  
  /* Interface terminal */
  printf("Vous allez jouer au jeu du devin.\nPour cela, vous devez penser tres fort a une personne.\n");
  printf("Appuyez sur une touche lorsque vous etes prets!\n");
  scanf("%d",&x);
  printf("\nSuper ! Nous allons pouvoir commencer ...\n\n");
  printf("Je vais tenter de deviner votre personnage en vous posant 20 questions. C'est parti !\n");
  
  /* Appel des differentes fonctions crees */
  for(i=0;i<20;i++){
    
    printf("Question %d : ",i);
    /* q=pose_question(personnages);*/
    printf("\n");
    printf("Votre reponse :\nSurement (1)\tProbablement oui (2)\nJe ne sais pas (3)\tProbablement non (4)\nSurement pas (5)\n");
    scanf("%d",&choix);
    /* maj_note_perso(personnages,choix,q);*/
  }
  printf("Ok je pense que j'ai trouvé ! Votre personnage est ... ");
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
    /* creer_personnage(population.txt,nom,rep); */
    printf("Quelle question aurait-pu permettre de trouver votre personnage ?\n");
    scanf("%s",&quest);
    /* creer_question(questions.txt,quest); */
  }}
