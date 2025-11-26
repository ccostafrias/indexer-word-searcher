#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "comandos.h"
#include "estrutura.h"
#include "utils.h"

void preenche_comandos() {
  // TODO: adicionar comandos de 'print', 'help', 
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
  int comparacoes = 0;
  int ocorrencias = 0;
  // TODO: implementar lista ligada para guardar o INDICE de todas as LINHAS onde foram encontradas
  // ListaLigada * indiceLinhas;
  
  if (strcmp(comando, "busca") == 0) {
    pega_dados_estrutura(argumento, &ocorrencias, &comparacoes);

    if (ocorrencias >= 1) {
      printf("Existe(m) %d ocorrencia(s) da palavra '%s' na(s) seguinte(s) linha(s):\n", ocorrencias, argumento);
      // TODO: criar função que imprime as linhas
      // imprime_linhas(indiceLinhas);
    } else {
      printf("Palavra '%s' nao encontrada.\n", argumento);
    }

    printf("Numero de comparacoes: %d\n", comparacoes);
  }
}

void pede_comando() {
  char comando[256];
  char argumento[256];

  // TODO: ler comando igual lemos as linhas do arquivo, para evitar ficar palavras no buffer
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