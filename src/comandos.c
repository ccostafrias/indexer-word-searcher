#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "comandos.h"
#include "lista_sequencial.h"
#include "utils.h"

void preenche_comandos() {
  listaComandos = cria_lista(NUM_COMANDOS);
  push(listaComandos, "busca");
}

Boolean valida_comando(char * comando) {
  if (strcmp(comando, "fim") == 0) return FALSE;

  int achouComando = busca_sequencial(listaComandos, comando);
  if (achouComando == -1) {
    printf("Opcao invalida!\n");
    return FALSE;
  }
  return TRUE;
}

void executa_comando(char * comando, char * argumento) {
  Boolean achou = FALSE;
  int comparacoes = 0;
  int ocorrencias = 0;
  // ListaLigada * indiceLinhas;
  // TODO: implementar lista ligada para guardar o INDICE de todas as LINHAS onde foram encontradas
  
  if (strcmp(comando, "busca") == 0) {
    if (strcmp(TIPO_INDICE, "arvore") == 0) {
      // lógica pra tipo ARVORE
    } else if (strcmp(TIPO_INDICE, "lista") == 0) {
      // lógica para tipo LISTA
      
    }

    if (achou) {
      printf("Existe(m) %d ocorrencia(s) da palavra %s na(s) seguinte(s) linha(s):\n", ocorrencias, argumento);
      // imprime_linhas(indiceLinhas);
      // TODO: criar função que imprime as linhas
    } else {
      printf("Palavra '%s' nao encontrada.\n", argumento);
    }

    printf("Numero de comparacoes: %d\n", comparacoes);
  }
}

void pede_comando() {
  char comando[256];
  char argumento[256];

  do {
    printf("> ");
    scanf(" %s", comando);
    tolower_string(comando);
    if (!valida_comando(comando)) continue;
    scanf(" %s", argumento);
    tolower_string(argumento);
    executa_comando(comando, argumento);

  } while (strcmp(comando, "fim") != 0);
}