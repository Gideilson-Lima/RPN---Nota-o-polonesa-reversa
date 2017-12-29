#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM 400

typedef struct no{
	char simb;
	struct no *prox;
}List;

List *last(List **l){
	List *paux = *l;
	if(paux!=NULL){
		while(paux->prox!=NULL){
			paux = paux->prox;
		}
	}else
		return NULL;
	
	return paux;
}
void add(List **l, char c){
	List *pnovo;
	
	if(*l==NULL){
		pnovo = malloc(sizeof(List));
		pnovo->simb = c;
		pnovo->prox = NULL;
		*l = pnovo;
		
	}else{
		pnovo = malloc(sizeof(List));
		pnovo->simb = c;
		pnovo->prox = *l;
		*l = pnovo;
		
	}
}
int rmv(List **l){
	List *paux = *l;
	if(paux->prox!=NULL){
		*l = paux->prox;
		free(paux);
		return 1;
	}else{
		free(*l);
		return 0;
	}
	
}

int qualsimb(char s){
	switch(s){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/': 
			return 2;
		case '^':
			return 3;
		case '(':
			return 4;
		case ')':
			return 5;
		default:
			return 0;
	}
	return -1;
}

void treat(List ** l, char *s){
	int simb; List *paux;
	
	for(int i=0;i<strlen(s);i++){
		simb = qualsimb(s[i]);
		paux = *l;
		if(simb==0){
			printf("%c",s[i]);
		}else if(simb >0 && simb <4){
			add(l,s[i]);
		}else if(simb == 5){
			printf("%c",paux->simb);
			rmv(l);
		}
	}
}
int main(int argc, char *argv[]){
	List *l =NULL;
	char expr[TAM];
	int qtd;
	printf("Digite a quantidade de expressões: ");
	scanf("%d",&qtd);
	for(int i =0; i<qtd;i++){
		printf("Digite a expressão:");
		scanf("%s",expr);
		treat(&l,expr);
		printf("\n");
	}
	return 0;
}

