#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{	
	char nome[100];
	FILE * fp;
	do{
		printf("nome do arquivo:");
		scanf("%s",nome);
		fp=fopen(nome,"r");
		printf("[%s]",nome);
	
		if(fp==NULL){
			printf("NAO TEM\n");
		}else{
			printf("EXISTE\n");
			fclose(fp);
		}
	}while(strcmp(nome,"fim")!=0);
	
return 0;
}
