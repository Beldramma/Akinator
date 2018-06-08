#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nb_perso 9

typedef struct personnage {
	char nom_perso[70];
	int note_perso;
	int liste_reponse[15];
} Personnage;

void perso_reponse(Personnage* l)
{
	FILE* flux;
	flux=fopen("Population.txt","r");
	int c;
	int cp=0;
	int i=0,j=0;
	/*l=(Question*)malloc(sizeof(Question));*/
	
	while ((feof(flux)==0)&&(i<nb_perso))
	{
		fgets(l[i].nom_perso,sizeof(l[i].nom_perso),flux);
		i++;
		cp=0;
		while (cp<8 ) 
		{
			c=fgetc(flux);
			
			if ((c!=' ')&&(c!='\n'))
			{
				l[i].liste_reponse[cp]=c;
				cp++;
			}
			
		}
		while(((c=fgetc(flux))!='\n')&&(j==0))
		{
			
			if(c==EOF)
			{
				j=1;
			}
		}
	}
	printf("OK\n");
	fclose(flux);
}

int main()
{
	Personnage P[10];
	int i,j;
	perso_reponse(P);
	for(i=0;i<nb_perso;i++)
	{
		puts(P[i].nom_perso);
		for(j=0;j<8;j++)
		{
			printf("%d\t",P[i].liste_reponse[j]);
		}
		printf("\n");
	}
	
	return 0;
}
