#include <stdio.h>

int note_question(int nb_qst, Liste_Perso *liste_perso) {    

  int i, j, Q;
  int reponses[nb_rep];
  personnage* ptr_cour;
  /* reponses: tableau avec le nombre de chaque reponse (incrementée selon les reponses des personnages) */  
  ptr_cour=liste_perso->tete;  
  for (i=0; i<nb_perso; i++) {     /*parcourir les personnages*/
      reponses[ptr_cour->liste_reponses[nb_qst]->chiffre_reponse]++;
      ptr_cour=ptr_cour->suivant;
  }
  Q=1;
  for (i=0; i<nb_rep; i++) {
    Q=Q*(reponses[i]+1);
  }

  return Q;
}



void pose_question(Liste_Perso liste_perso) {
  int indice_question=0, i;
  
  m=note_question(0, liste_perso);  
  for (i=0; i<nb_qst-1; i++) { 
      if (note_question(i+1, liste_perso)>m){
	m=note_question(i+1, liste_perso);
	indice_question=i;
      }
  }
  /* afficher la question numéro "indice_question" */
  return;
}
