#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_ligada.h"

ListaLigada * cria_lista_ligada(){

	ListaLigada * lista =  (ListaLigada *) malloc (sizeof(ListaLigada));
	lista->primeiro = NULL;
	lista->tamanho = 0;
	
	return lista;
}

void destroi_lista(ListaLigada * lista){

	No * p = lista->primeiro;
	No * tmp;

	while(p){
		
		tmp = p;
		p = p->proximo;
		free(tmp);
	}

	free(lista);
}

void imprime_ligada(ListaLigada * lista){

	No * p;

	printf("Lista:");
	int i = 0;
	for(p = lista->primeiro; p; p = p->proximo){

		printf("indice: %d, %s\n", i, p->valor);
		i++;
	}

	printf("\n");
}

int busca_ligada(ListaLigada * lista, Elemento e){

	int i = 0;
	No * p = lista->primeiro;

	while(p && p->valor != e){
		p = p->proximo;
		i++;
	}

	return p ? i : -1;
}

Boolean insere_ligada(ListaLigada * lista, Elemento e){

	int i, antecessor;

	No * p;
	No * novo = (No *) malloc(sizeof(No));

	novo->valor = (char *) malloc((strlen(e) + 1) * sizeof(char));
	strcpy(novo->valor, e);
	
	if(lista->tamanho == 0){
		novo->proximo = lista->primeiro;
		lista->primeiro = novo;
	}
	else {
		i = 0;
		antecessor = lista->tamanho - 1;
		p = lista->primeiro;

		while(i < antecessor){
			i++;
			p = p->proximo;
		}
	
		novo->proximo = p->proximo;
		p->proximo = novo;
	}
	lista->tamanho++;
	return TRUE;
}