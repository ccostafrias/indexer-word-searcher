#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_ligada_char.h"
#include "lista_ligada_int.h"
#include "lista_sequencial.h"

extern ListaSequencial * linhas;

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

    printf("Lista:\n");
    int i = 0;
    for(p = lista->primeiro; p; p = p->proximo){
        printf("indice: %d, %s, %d\n", i, p->valor, p->quantidade);

        NoInt *q = p->linhas_texto->primeiro;

        while (q) {
            printf("[%d]: ", q->valor);
            imprime_indice(linhas, q->valor);
            printf("\n");
            q = q->proximo;
        }
        
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

Boolean insere_ligada_char(ListaLigadaChar * lista, ElementoChar e, int linha){
    
    NoChar * p = lista->primeiro;
    NoChar * anterior = NULL;

    while (p != NULL) {
        if (strcmp(p->valor, e) == 0) {
            p->quantidade++;
            
            if (p->linhas_texto == NULL) {
                p->linhas_texto = cria_lista_ligada_int();
            }
            
            insere_ligada_int(p->linhas_texto, linha);
            
            return TRUE;
        }
        
        anterior = p;
        p = p->proximo;
    }


    NoChar * novo = (NoChar *) malloc(sizeof(NoChar));
    
    novo->valor = (char *) malloc((strlen(e) + 1) * sizeof(char));
    strcpy(novo->valor, e);
    
    novo->quantidade = 1;
    novo->proximo = NULL;
    
    novo->linhas_texto = cria_lista_ligada_int();
    insere_ligada_int(novo->linhas_texto, linha);

    if (anterior == NULL) {
        lista->primeiro = novo;
    } else {
        anterior->proximo = novo;
    }

    lista->tamanho++;
    return TRUE;
}
