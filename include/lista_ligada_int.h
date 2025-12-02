#ifndef LISTA_LIGADA_INT_H
#define LISTA_LIGADA_INT_H

#define FALSE 0
#define TRUE 1

typedef int Boolean;
typedef int ElementoInt;

typedef struct _lista_ligada_int_ ListaLigadaInt;

typedef struct _noint_ {
    ElementoInt valor;
    struct _noint_ * proximo;
} NoInt;

struct _lista_ligada_int_ {
    NoInt * primeiro;
    int tamanho;
};

ListaLigadaInt * cria_lista_ligada_int();
void destroi_ligada_int(ListaLigadaInt * lista);
Boolean insere_ligada_int(ListaLigadaInt * lista, ElementoInt e);

#endif
