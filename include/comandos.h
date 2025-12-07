#ifndef COMANDOS_H
#define COMANDOS_H

#include "lista_sequencial.h"
#include "lista_ligada_char.h"
#include "lista_ligada_int.h"
#include "estrutura.h"
#include "utils.h"

typedef enum {
  CMD_BUSCA,
  CMD_PRINT,
  CMD_HELP,
  CMD_FIM,
  NUM_COMANDOS,
} ComandoID;

typedef void (*FuncaoComando)(ListaLigadaChar * args);

typedef struct {
  const char * nome;
  const FuncaoComando func;
  const char * descricao;
  const int args;
} Comando;

// VARIÁVEIS GLOBAIS
extern ListaSequencial * linhas;
extern void * estrutura;

void pede_comando();

#endif