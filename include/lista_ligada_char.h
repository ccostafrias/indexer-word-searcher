#ifndef LISTA_LIGADA_CHAR_H
#define LISTA_LIGADA_CHAR_H

#include "lista_ligada_int.h"

#define FALSE 0
#define TRUE 1

typedef int Boolean;
typedef char* ElementoChar;

typedef struct _lista_ligada_char_ ListaLigadaChar;

typedef struct _nochar_ {
    ElementoChar valor;
    int quantidade;
    ListaLigadaInt *linhas_texto;
    struct _nochar_ * proximo;
} NoChar;

struct _lista_ligada_char_ {
    NoChar * primeiro;
    int tamanho;
};

ListaLigadaChar * cria_lista_ligada_char();
NoChar * busca_ligada_char(ListaLigadaChar * lista, ElementoChar e, int * comparacoes);
void destroi_ligada_char(ListaLigadaChar * lista);
void imprime_ligada_char(ListaLigadaChar * lista);
void dados_ligada_char(ListaLigadaChar * lista, char * palavra, int * ocorrencias, int * comparacoes);
int tamanho_lista_ligada_char(ListaLigadaChar * lista);
Boolean insere_ligada_char(ListaLigadaChar * lista, ElementoChar e, int linha);

#endif
