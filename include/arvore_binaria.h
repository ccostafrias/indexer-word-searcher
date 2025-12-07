#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "lista_ligada_int.h"

#define FALSE 0
#define TRUE 1

#define INDEFINIDO -1
#define ESQUERDO 0
#define DIREITO 1

typedef char * Elemento;
typedef int Boolean;

typedef struct _no_arvore_ {
	Elemento valor;
	int quantidade;
	int h;

	ListaLigadaInt *linhas_texto;
	struct _no_arvore_ * esq;
	struct _no_arvore_ * dir;

} NoBin;

typedef struct {
	NoBin * raiz;
	int len;
} Arvore;

Arvore * cria_arvore();
NoBin * busca_bin(Arvore * arvore, Elemento e, int * comparacoes);
void imprime_arvore(Arvore * arvore);
void dados_arvore(Arvore * arvore, char * palavra, int * ocorrencias, int * comparacoes, ListaLigadaInt ** indiceLinhas);
int pega_altura(Arvore * arvore);
int tamanho_arvore(Arvore * arvore);
Boolean insere_bin(Arvore * arvore, Elemento e, int linha, int * comparacoes);

void display_arvore(Arvore * arvore);

#endif