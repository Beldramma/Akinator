#include <stdio.h>

int note_question(int nb_qst, Liste_Perso *liste_perso) {    

  int i, j, Q;
  int reponses[nb_rep];
  personnage* ptr_cour;
  /* reponses: tableau avec le nombre de chaque reponse (incrementée selon les reponses des personnages) */  
  ptr_cour=liste_perso->tete;  
  for (i=0; i<nb_perso; i++) {     /*parcourir les personnages*/
    for (j=0; j<nb_rep; j++) {    /*parcourir les reponses*/
      reponses[ptr_cour->liste_reponses[nb_qst]->chiffre_reponse]++;
      ptr_cour=ptr_cour->suivant;
    }
  }
  Q=1;
  for (i=0; i<nb_rep; i++) {
    Q=Q*(reponses[i]+1);
  }

  return Q;
}
