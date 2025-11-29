#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#define NUM_ESTRUTURAS 3

// VARIÁVEIS GLOBAIS
extern void * estrutura;

typedef int Boolean;

// guarda ponteiros genérios para todas as operações possíveis em cada estrutura
typedef struct Operacoes {
  void   *(*cria)();
  void    (*imprime)(void * estrutura);
  int     (*tamanho)(void * estrutura);
  void    (*dados)(void * estrutura, char * palavra, int * ocorrencias, int * comparacoes);
  Boolean (*insere)(void * estrutura, char * palavra, int linha);
} Operacoes;

typedef enum {
  LIGADA,
  ARVORE,
  HASH,
} TipoEstrutura;

extern TipoEstrutura TIPO;

void * cria_estrutura();
void cria_funcoes();
void imprime_estrutura();
void pega_dados_estrutura(char * palavra, int * ocorrencias, int * comparacoes);
int tamanho_estrutura();
Boolean insere_estrutura(char * palavra, int linha);

#endif