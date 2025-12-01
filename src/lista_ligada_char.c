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
	FILE *fp = fopen("build/lista.out", "w");
    NoChar * p;

    fprintf(fp, "Lista:\n");
    int i = 0;
    for (p = lista->primeiro; p; p = p->proximo){
        fprintf(fp, "| i: %03d | %-16s | qtd: %02d |", i, p->valor, p->quantidade);

        if (p->proximo) {
            fprintf(fp, "\n");
        }

        // NoInt *q = p->linhas_texto->primeiro;

        // while (q) {
        //     fprintf(fp, "[%d]: ", q->valor);
        //     fprintf(fp, "\n");
        //     q = q->proximo;
        // }
        
        i++;
    }

    fclose(fp);
}

NoChar * busca_ligada_char(ListaLigadaChar * lista, ElementoChar e, int * comparacoes){
    NoChar * p = lista->primeiro;

    (*comparacoes)++;
    while (p && strcmp(p->valor, e) != 0){
        (*comparacoes)++;
        p = p->proximo;
    }

    return p;
}

int tamanho_lista_ligada_char(ListaLigadaChar * lista){
    return lista->tamanho;
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

void dados_ligada_char(ListaLigadaChar * lista, char * palavra, int * ocorrencias, int * comparacoes) {
	NoChar * node = busca_ligada_char(lista, palavra, comparacoes);

	if (node) {
		*ocorrencias = node->quantidade;
	}
}