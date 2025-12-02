#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "lista_ligada_int.h"
#include "lista_sequencial.h"

#define NUM_ESTRUTURAS 3

// VARIÁVEIS GLOBAIS
extern void * estrutura;

typedef int Boolean;

typedef void * (*FuncaoCria)();
typedef void (*FuncaoImprime)(void *);
typedef void (*FuncaoDados)(void *, char *, int *, int *, ListaLigadaInt **);
typedef int (*FuncaoTamanho)(void *);
typedef Boolean (*FuncaoInsere)(void *, char *, int, int *);

// guarda ponteiros genérios para todas as operações possíveis em cada estrutura
typedef struct Operacoes {
  void   *(*cria)();
  void    (*imprime)(void * estrutura);
  int     (*tamanho)(void * estrutura);
  void    (*dados)(void * estrutura, char * palavra, int * ocorrencias, int * comparacoes, ListaLigadaInt ** indiceLinhas);
  Boolean (*insere)(void * estrutura, char * palavra, int linha, int * comparacoes);
} Operacoes;

typedef enum {
  LIGADA,
  ARVORE,
  HASH,
} TipoEstrutura;

extern TipoEstrutura TIPO;
extern ListaSequencial * linhas;

void * cria_estrutura();
void cria_funcoes();
void imprime_estrutura();
void pega_dados_estrutura(char * palavra, int * ocorrencias, int * comparacoes, ListaLigadaInt ** indiceLinhas);
int tamanho_estrutura();
Boolean insere_estrutura(char * palavra, int linha, int * comparacoes);

void imprime_linhas(ListaLigadaInt * linhasNum);

#endif