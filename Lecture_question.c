#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nb_question;

typedef struct lecture_question {
	int numero;
	char question[70];
}Question;


void question(Question* l)
{
	FILE* flux;
	flux=fopen("Questions.txt","r");
	char c;
	while((c=fgetc(flux))!=EOF)
	{
		if(c=='\n')
		{
			nb_question++;
		}
	}
	fseek(flux,0,SEEK_SET);
	printf("Nombre de question:%d\n",nb_question);
	int j=0;
	/*l=(Question*)malloc(sizeof(Question));*/
		
	while (/*(feof(flux)==0)&&*/(j<nb_question))
	{
		fgets(l[j].question,70,flux);
		l[j].numero=j;
		j++;	
	}
	fclose(flux);
}

int main()
{
	Question* Q;
	Q=(Question*)malloc(10*(sizeof(Question)));
	int i;
	question(Q);
	for(i=0;i<nb_question;i++)
	{
		puts(Q[i].question);
	}
	
	return 0;
}
