#ifndef HASH_H
#define HASH_H

#include "lista_ligada_char.h"

#define FALSE 0
#define TRUE 1

#define TAMANHO_HASH 100

typedef int Boolean;
typedef char* ElementoChar;

typedef struct _hash_ Hash;

struct _hash_ {
    ListaLigadaInt * idx;
    ListaLigadaChar ** a;
    int tamanho;
};

Hash * cria_hash();
NoChar * busca_hash(Hash * hash, ElementoChar e, int * comparacoes);
void display_hash(Hash * hash);
void imprime_hash(Hash * hash);
void dados_hash(Hash * hash, char * palavra, int * ocorrencias, int * comparacoes, ListaLigadaInt ** indiceLinhas);
int tamanho_hash(Hash * hash);
Boolean insere_hash(Hash * hash, ElementoChar e, int linha, int * comparacoes);

#endif
