#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#define FALSE 0
#define TRUE 1

typedef int Boolean;
typedef char* Elemento;

typedef struct _lista_ligada_ ListaLigada;

typedef struct _no_ {
	Elemento valor;
	int quantidade;
	ListaLigada *linhas_texto;
	struct _no_ * proximo;
} No;

struct _lista_ligada_ {
	No * primeiro;
	int tamanho;
};

ListaLigada * cria_lista_ligada();
void destroi_lista(ListaLigada * lista);
void imprime_ligada(ListaLigada * lista);
int busca_ligada(ListaLigada * lista, Elemento e);
Boolean insere_ligada(ListaLigada * lista, Elemento e);

#endif