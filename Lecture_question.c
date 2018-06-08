#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nb_question 8

typedef struct lecture_question {
	int numero;
	char question[70];
}Question;


void question(Question* l)
{
	FILE* flux;
	flux=fopen("Questions.txt","r");
	
	int j=0;
	/*l=(Question*)malloc(sizeof(Question));*/
		
	while ((feof(flux)==0)&&(j<nb_question))
	{
		fgets(l[j].question,sizeof(l[j].question),flux);
		l[j].numero=j;
		j++;	
	}
	fclose(flux);
}

int main()
{
	Question Q[10];
	int i;
	question(Q);
	for(i=0;i<nb_question;i++)
	{
		puts(Q[i].question);
	}
	
	return 0;
}
