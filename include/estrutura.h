#ifndef ESTRUTURA_H
#define ESTRUTURA_H

// VARIÁVEIS GLOBAIS
extern char TIPO_INDICE[];
extern void * estrutura;

int tamanho_estrutura();
void cria_estrutura();
void imprime_estrutura();
void insere_estrutura(char * palavra, int linha);
void pega_dados_estrutura(char * palavra, int * ocorrencias, int * comparacoes);

#endif