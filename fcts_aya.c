#include <stdio.h>
/*-----------------------------------------*/
int note_question(int nb_qst) {    

  int i, j, Q;

  /* reponses: tableau avec le nombre de chaque reponse (incrementée selon les reponses des personnages) */
  
  for (i=0; i<nb_perso; i++) {     /*parcourir les personnages*/
    for (j=0; j<nb_rep; j++) {    /*parcourir les reponses*/
        reponses[personnage->vecteur_reponse[j]]++;
    }
  }

  
  Q=1;
  for (i=0; i<nb_rep; i++) {
    Q=Q*(reponses[i]+1);
  }

  return Q;
}
		     
/*-----------------------------------------*/       

int note_personnage(int* nouveau_reponses, int* perso_reponses) {  /*recuperer les reponses de l'utilisateur et le perso avec lequel on compare*/
  int k, i, j, m, n=0;

  for (k=1; k<qst; k++) {
    i=nouveau_reponses[k]; /*reponse donnée*/
    j=perso_reponses[k];  /*reponse attendue*/
  
    m=i-j;

    if ( (m==1) || (m=-1) ) {
      n=n+1;
    }
    
    else {
      if ( (m==2) || (m=-2) ) {
	n=n-1;
      }
      
      else {
	if ( (m==3) || (m=-3) ) {
	  n=n-2;
	}
	
	else {
	  if ( (m==4) || (m=-4) ) {
	    n=n-3;
	  }
	  
	  else {
	    n=n+3;
	  }
	}
      }
    }
  }
  return n;
}

    
    
 /*-----------------------------------------*/   
    
    
/*void maj_note_perso(personnages)    entrée :  liste chainée personnages        sortie :   /   fonctionnement: utilise la fonction note_perso pour toute la liste de personnages restants
 */


void maj_note_perso(Liste_Perso* liste_perso) {

  ptr_cour=liste_perso->tete;
  for (i=1; i<liste_perso->nb_perso; i++) {
    ptr_cour->note_perso=note_personnage(nouveau_reponses, ptr_cour->liste_reponse);
    ptr_cour=ptr_cour->suivant;
  }
}


/*-----------------------------------------*/   


/*void pose_question(personnages)   entrée : structure personnages   sortie : numéro de la question   fonctionnement : pose une question en cohérence avec les résultats précédents (comparer les notes des questions)*/



void pose_question(Liste_Perso liste_perso) {

  int indice_question=1, i;
  m=note_question(1);  
  for (i=1; i<nb_qst-1; i++) { 
      if (note_question(i+1)>m){
	m=note_question(i+1);
	indice_question=i;
      }
  }
  /* afficher la question numéro "indice_question" */
  return;


/*-----------------------------------------*/   

   
    
