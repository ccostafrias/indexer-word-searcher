#ifndef COMANDOS_H
#define COMANDOS_H

#include "lista_sequencial.h"

#define NUM_COMANDOS 10

// VARIÁVEIS GLOBAIS
extern ListaSequencial * listaComandos;
extern ListaSequencial * linhas;
extern void * estrutura;

Boolean valida_comando(char * comando);
void executa_comando(char * comando, char * argumento);
void preenche_comandos();
void pede_comando();

#endif