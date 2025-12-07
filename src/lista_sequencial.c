#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_sequencial.h"

ListaSequencial * cria_lista(int capacidade){

	ListaSequencial * lista =  (ListaSequencial *) malloc (sizeof(ListaSequencial));
	lista->a = (Elemento *) malloc ((capacidade + 1) * sizeof(Elemento));
	lista->capacidade = capacidade;
	lista->livre = 0;

	return lista;
}

void destroi_sequencial(ListaSequencial * lista){
	for(int i = 0; i < lista->livre; i++){
		free(lista->a[i]);
	}

	free(lista->a);
	free(lista);
}

int tamanho(ListaSequencial * lista){
	return lista->livre;
}

int busca_sequencial(ListaSequencial * lista, Elemento e){
	for(int i = 0; i < lista->livre; i++){
		if (strcmp(lista->a[i], e) == 0){
			return i;
		}
	}

	return -1;
}

Boolean push(ListaSequencial * lista, Elemento e){
	if (lista->livre >= lista->capacidade) return FALSE;

	lista->a[lista->livre] = (char*) malloc((strlen(e) + 1) * sizeof(char));
	strcpy(lista->a[lista->livre], e);

	lista->livre++;

	return TRUE;

}

void imprime_indice(ListaSequencial * lista, int index) {
	printf("%s\n", lista->a[index]);
}

void imprime(ListaSequencial * lista){
	int i;

	printf("Lista:");

	for(i = 0; i < lista->livre; i++) {
		imprime_indice(lista, i);
	}

	printf("\n");
}