#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "comandos.h"

// ====================================
// == COMANDOS
// ====================================

const Comando comandos[NUM_COMANDOS];

void executa_comando_busca(ListaLigadaChar * linhaComandos) {
  NoChar * proximo = linhaComandos->primeiro->proximo;

  char * palavra = proximo->valor;

  int comparacoes = 0;
  int ocorrencias = 0;
  ListaLigadaInt * indiceLinhas;

  pega_dados_estrutura(palavra, &ocorrencias, &comparacoes, &indiceLinhas);

  if (ocorrencias > 0) {
    printf("Existe(m) %d ocorrencia(s) da palavra '%s' na(s) seguinte(s) linha(s):\n", ocorrencias, palavra);
    imprime_linhas(indiceLinhas);
  } else {
    printf("Palavra '%s' nao encontrada.\n", palavra);
  }

  printf("Numero de comparacoes: %d\n", comparacoes);
}

void executa_comando_fim() {
  exit(0);
}

void executa_comando_print(ListaLigadaChar * linhaComandos) {
  imprime_estrutura();
}

void executa_comando_help() {
  for (int i = 0; i < NUM_COMANDOS; i++) {
    printf("%-10s %s\n", comandos[i].nome, comandos[i].descricao);
  }
}

// ====================================
// == FUNÇÕES GERAIS
// ====================================

const Comando comandos[NUM_COMANDOS] = {
  [CMD_BUSCA] = { "busca", executa_comando_busca, "Procura por uma palavra dentro do texto",  2 },
  [CMD_PRINT] = { "print", executa_comando_print, "Imprime cada palavra encontrada no texto", 1 },
  [CMD_HELP]  = { "help",  executa_comando_help,  "Mostra a lista de comandos disponiveis",   1 },
  [CMD_FIM]   = { "fim",   executa_comando_fim,   "Finaliza o programa",                      1 },
};

int encontra_comando_idx(const char * nome) {
  for (int i = 0; i < NUM_COMANDOS; i++) {
    if (strcmp(nome, comandos[i].nome) == 0) 
      return i;
  }

  return -1;
}

void chama_comando(ListaLigadaChar * linhaComandos) {
  if (linhaComandos == NULL || linhaComandos->primeiro == NULL) {
    printf("Comando vazio!\n");
    return;
  }
  
  char * comando = linhaComandos->primeiro->valor;
  int idx = encontra_comando_idx(comando);

  // comando nao encontrado
  if (idx < 0) {
    printf("Opcao invalida!\n");
    return;
  }

  // numeros de argumentos passado menor do que o necessario
  if (tamanho_lista_ligada_char(linhaComandos) < comandos[idx].args) {
    printf("Argumentos insuficientes\n");
    return;
  }

  comandos[idx].func(linhaComandos);
}

void pede_comando() {
  char * buffer = (char *) malloc(256 * sizeof(char));
  char * cursor;
  char * palavra;

  while (TRUE) {
    printf("> ");
    scanf(" %255[^\n]", buffer);

    cursor = buffer;
    ListaLigadaChar * linhaComandos = cria_lista_ligada_char();

    // pegamos a frase recebida e transformamos cada palavras em tokens, que serão armazenados
    while ( (palavra = separa_string(&cursor, " -/")) ) {
      tolower_string(palavra);
      insere_ligada_char(linhaComandos, palavra, -1, NULL);
    }

    chama_comando(linhaComandos);
    destroi_ligada_char(linhaComandos);
  }
}