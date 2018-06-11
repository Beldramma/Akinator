#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fonctions.h"


/* Programme principal */

int main(){

    int choix;
    Question* Q;
    Liste_Perso *ptr_liste;
	Personnage *P;
    int nb_reponse=69;

	Q=(Question*)malloc(10*(sizeof(Question)));

	question(Q);
	/*for(i=0;i<8;i++)
	{
		puts(Q[i].question);
	}*/
	ptr_liste=recuperation_nom_reponse();	
	printf("nombre_perso=%d\n",ptr_liste->nb_perso);
	P=(Personnage*)malloc(sizeof(Personnage));
	P->nom_perso=(char*)malloc(13*sizeof(char));
	P->liste_reponse=(int*)malloc(nb_reponse*sizeof(int));
	jeu(P,ptr_liste,Q);
	ecriture_fichier(P);

    printf("\nSouhaitez-vous rejouer ? Oui(0)  Non(1)\n");
    scanf("%d",&choix);
    if(choix==0){
    jeu(P,ptr_liste,Q);
	}
    return 0;}

