#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//VARIAVEIS E ESTRUTURAS +----------------------
typedef struct{
	int id;
	char words[30];
}TWORD;

FILE *archive; // arquivo
int countwords; // quantidade de palavras no arquivo
TWORD list[5000]; // lista de palavras

//FUNÇÕES +-------------------------------------
void openfile(){
	char filename[30]; // nome do arquivo.txt
	printf("-----------------------\n");
	printf("Digite o nome do arquivo: ");
	scanf("%s", &filename);
	archive = fopen(filename, "r");
	
	if(archive != NULL){
		printf("SUCESSO, arquivo \'%s\' aberto.\n", filename);
	}else{
		printf("ERRO, arquivo \'%s\' não encontrado.\n", filename);
	}
}

/*void viewfile(){
	countwords = 0; // zerando contador (!)
	char tempwords[30]; // variavel para capturar palavras
	
	printf("-----------------------\n");
	while(!feof(archive)){
		fscanf(archive, "%s", &tempwords);
		
		if((tempwords[strlen(tempwords)-1] == ',') || 
		   (tempwords[strlen(tempwords)-1] == ':') || 
           (tempwords[strlen(tempwords)-1] == '.')){
           	
			tempwords[strlen(tempwords) -1] = '\0';
			printf("%s\n", tempwords);
		}else{
			printf("%s\n", tempwords);
		}
		countwords++;	
	}
	printf("-----------------------\n");
	printf("Palavras PROCESSADAS: %d\n", countwords);
}*/

void loadlist(){
	countwords = 0; // zerando o contador (!)
	char tempwords[30]; // variavel para capturar palavras
	printf("-----------------------\n");
	while(!feof(archive)){
		fscanf(archive, "%s", &tempwords);
		
		if((tempwords[strlen(tempwords)-1] == ',') || 
		   (tempwords[strlen(tempwords)-1] == ':') || 
           (tempwords[strlen(tempwords)-1] == '.')){
           	
			tempwords[strlen(tempwords) -1] = '\0';
		}
		list[countwords].id = countwords;
		strcpy(list[countwords].words, tempwords);
		countwords++;	
	}
	printf("Palavras ARMAZENADAS: %d\n", countwords);
}

void viewlist(){
	int i;
	printf("-----------------------\n");
	for(i = 0; i < countwords; i++){
		printf("%d: %s\n", list[i].id, list[i].words);
	}
}

int menu(){
	int selection;
	printf("(1) abrir arquivo\n");
	printf("(2) carregar lista\n");
	printf("(3) mostrar lista\n");
	printf("(4) pesquisa linear\n");
	printf("(9) sair do programa\n");
	printf("-----------------------\n");
	printf("(>) Digite uma opção: ");
	scanf("%d", &selection);
	return selection;
}

//FUNÇÃO PRINCIPAL +----------------------------
int main(){
	setlocale(LC_ALL, "Portuguese");
	int op;
	
	
	
	do{
		op = menu();
		switch(op){
			case 1:
				openfile();
				break;
			case 2:
				loadlist();
				break;
			case 3:
				viewlist();
				break;
			case 4:
				break;
			case 5:
				break;
		}  
		system("pause");
		system("cls");	
	}while(op != 9);
	
	
	return 0;	
}