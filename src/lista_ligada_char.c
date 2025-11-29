#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_ligada_char.h"

ListaLigadaChar * cria_lista_ligada_char(){

    ListaLigadaChar * lista =  (ListaLigadaChar *) malloc (sizeof(ListaLigadaChar));
    lista->primeiro = NULL;
    lista->tamanho = 0;
    
    return lista;
}

void destroi_ligada_char(ListaLigadaChar * lista){

    NoChar * p = lista->primeiro;
    NoChar * tmp;

    while(p){
        
        tmp = p;
        p = p->proximo;
        free(tmp);
    }

    free(lista);
}

void imprime_ligada_char(ListaLigadaChar * lista){

    NoChar * p;

    printf("Lista:");
    int i = 0;
    for(p = lista->primeiro; p; p = p->proximo){

        printf("indice: %d, %s\n", i, p->valor);
        i++;
    }

    printf("\n");
}

int busca_ligada_char(ListaLigadaChar * lista, ElementoChar e){

    int i = 0;
    NoChar * p = lista->primeiro;

    while(p && p->valor != e){
        p = p->proximo;
        i++;
    }

    return p ? i : -1;
}

Boolean insere_ligada_char(ListaLigadaChar * lista, ElementoChar e){

    int i, antecessor;

    NoChar * p;
    NoChar * novo = (NoChar *) malloc(sizeof(NoChar));

    novo->valor = (char *) malloc((strlen(e) + 1) * sizeof(char));
    strcpy(novo->valor, e);
    
    if(lista->tamanho == 0){
        novo->proximo = lista->primeiro;
        lista->primeiro = novo;
        lista->tamanho++;
    }
    else {
        i = 0;
        antecessor = lista->tamanho - 1;
        p = lista->primeiro;

        while(i < antecessor){
            if(strcmp(p->valor, e) == 0) {
                p->quantidade++;
                break;
            }
            i++;
            p = p->proximo;
        }
    
        if (i == antecessor) {
            novo->proximo = p->proximo;
            p->proximo = novo;
            lista->tamanho++;
        }
    }
    return TRUE;
}
