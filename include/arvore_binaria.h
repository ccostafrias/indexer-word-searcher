#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "lista_ligada.h"

#define FALSE 0
#define TRUE 1

#define INDEFINIDO -1
#define ESQUERDO 0
#define DIREITO 1

typedef char * Elemento;
typedef int Boolean;

typedef struct _no_arvore_ {
	Elemento valor;
	int c;
	int h;

	ListaLigada *linhas_texto;
	struct _no_arvore_ * esq;
	struct _no_arvore_ * dir;

} NoBin;

typedef struct {
	NoBin * raiz;
	int h;

} Arvore;

Arvore * cria_arvore();
void imprime_bin(Arvore * arvore);
NoBin * busca_bin(Arvore * arvore, Elemento e);
Boolean insere_bin(Arvore * arvore, Elemento e);

void display(Arvore * arvore);

#endif