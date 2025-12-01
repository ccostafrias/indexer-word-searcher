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

void imprime_ligada_int(ListaLigadaInt * lista){

    NoInt * p;

    printf("Lista:");
    int i = 0;
    for(p = lista->primeiro; p; p = p->proximo){

        printf("indice: %d, %s\n", i, p->valor);
        i++;
    }

    printf("\n");
}

Boolean insere_ligada_int(ListaLigadaInt * lista, ElementoInt e){

    int i, antecessor;

    NoInt * p;
    NoInt * novo = (NoInt *) malloc(sizeof(NoInt));
    novo->valor = e;

    
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
