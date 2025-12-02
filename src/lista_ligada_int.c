#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_ligada_int.h"

ListaLigadaInt * cria_lista_ligada_int(){

    ListaLigadaInt * lista =  (ListaLigadaInt *) malloc (sizeof(ListaLigadaInt));
    lista->primeiro = NULL;
    lista->tamanho = 0;
    
    return lista;
}

void destroi_ligada_int(ListaLigadaInt * lista){

    NoInt * p = lista->primeiro;
    NoInt * tmp;

    while(p){
        
        tmp = p;
        p = p->proximo;
        free(tmp);
    }

    free(lista);
}

Boolean insere_ligada_int(ListaLigadaInt * lista, ElementoInt e){
    
    NoInt * p = lista->primeiro;
    NoInt * anterior = NULL;
    
    while (p != NULL) {
        if (p->valor == e) {
            return FALSE;
        }

        anterior = p;
        p = p->proximo;
    }

    NoInt * novo = (NoInt *) malloc(sizeof(NoInt));
    novo->valor = e;
    novo->proximo = NULL;

    if (anterior == NULL) {
        lista->primeiro = novo; 
    } else {
        anterior->proximo = novo;
    }

    lista->tamanho++;
    return TRUE;
}
