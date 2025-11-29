#ifndef FILE_H
#define FILE_H

#include "lista_sequencial.h"
#include "estrutura.h"
#define TAMANHO 10000

// VARIÁVEIS GLOBAIS
extern TipoEstrutura TIPO;
extern ListaSequencial * linhas;

FILE * abre_arquivo(char * nomeArquivo);
void valida_args(int argc, char *argv[]);
void carrega_dados(FILE * in, int num_linhas);
int counting_lines(FILE * f);

#endif