#ifndef FILE_H
#define FILE_H

#include "lista_sequencial.h"
#define TAMANHO 10000

extern char TIPO_INDICE[32];
extern ListaSequencial * linhas;
extern void * estrutura;

FILE * abre_arquivo(char * nomeArquivo);
void valida_args(int argc, char *argv[]);
void carrega_dados(FILE * in, int num_linhas);
int counting_lines(FILE * f);

#endif