#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

Hash * cria_hash() {
    Hash * hash = (Hash *) malloc(sizeof(Hash));
    hash->a = (ListaLigadaChar**) malloc(TAMANHO_HASH * sizeof(ListaLigadaChar*));
    for (int i = 0; i < TAMANHO_HASH; i++) {
        hash->a[i] = cria_lista_ligada_char();
    }

    hash->idx = cria_lista_ligada_int();
	hash->tamanho = 0;

	return hash;
}

int hash_func(const char * key) {
    int acc = 0, k = 0;

    while (key[k] != '\0') {
        acc += (k+1) * key[k];
        k++;
    }

    return acc;
}

NoChar * busca_hash(Hash * hash, ElementoChar e, int * comparacoes) {
    int hashIdx = hash_func(e) % TAMANHO_HASH;

    return busca_ligada_char(hash->a[hashIdx], e, comparacoes);
}

void display_hash(Hash * hash) {
	FILE *fp = fopen("build/hash.out", "w");
    ListaLigadaChar * p;

    fprintf(fp, "Hash:\n");
    for (int i = 0; i < TAMANHO_HASH; i++) {
        p = hash->a[i];
        if (p->tamanho == 0) continue;

        fprintf(fp, "IDX: %04d ", i);
        for (int j = 0; j < p->tamanho; j++) {
            fprintf(fp, "■");
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void imprime_hash(Hash * hash) {
    NoInt * q;
    NoChar * p;

    printf("Elementos na tabela hash: \n");
    // hash->idx guardar todos os "hashs" que foram ocupados, a fim de evitar passar por celulas vazias
    for (q = hash->idx->primeiro; q; q = q->proximo) {
        // cada elemento de hash->a guarda uma ListaLigadaChar*, a qual armazena todas as colisoes daquele hash
        for (p = hash->a[q->valor]->primeiro; p; p = p->proximo) {
            printf("| hash: %03d | %-16s | qtd: %02d |\n", q->valor, p->valor, p->quantidade);
        }
    }
}

void dados_hash(Hash * hash, char * palavra, int * ocorrencias, int * comparacoes, ListaLigadaInt ** indiceLinhas) {
    int hashIdx = hash_func(palavra) % TAMANHO_HASH;
    NoChar * node = busca_ligada_char(hash->a[hashIdx], palavra, comparacoes);

	if (node) {
		*ocorrencias = node->quantidade;
		*indiceLinhas = node->linhas_texto;
	}
}

int tamanho_hash(Hash * hash) {
    return hash->tamanho;
}

Boolean insere_hash(Hash * hash, ElementoChar e, int linha, int * comparacoes) {
    int hashIdx = hash_func(e) % TAMANHO_HASH;
    
    if (insere_ligada_char(hash->a[hashIdx], e, linha, comparacoes)) {
        hash->tamanho++;
        insere_ligada_int(hash->idx, hashIdx);

        return TRUE;
    }

    return FALSE;
}
