int note_question(int nb_qst, Liste_Perso liste_personnage) 
{    

  int i,j, Q;
  int reponses[5];
  Personnage* ptr_cour;

	/* initialisation tableau */
	for (i=1; i<=5; i++) {
		reponses[i]=0; }

  /* reponses: tableau tel que l'indice de la case est la réponse et le contenu est le nombre d'occurence de la réponses chez les personnages (incrementée selon les reponses des personnages) */  
  ptr_cour=(Personnage*)malloc(sizeof(Personnage));
  ptr_cour=liste_personnage.tete;
  
  while(ptr_cour!=NULL) {     /*parcourir les personnages*/
  			
	reponses[ptr_cour->liste_reponse[nb_qst]]++;
	ptr_cour=ptr_cour->perso_suiv;
  }
	
  Q=1;
  for (i=1; i<6; i++) {
    Q=Q*(reponses[i]+1);
  }
  return Q;
}
