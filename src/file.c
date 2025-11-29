#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

#include "estrutura.h"
#include "file.h"

FILE * abre_arquivo(char * nomeArquivo) {
  FILE * in = fopen(nomeArquivo, "r");

  if (in == NULL) {
    printf("Arquivo inválido!");
    exit(1);
  }

  return in;
}

TipoEstrutura guarda_tipo(char * tipo_str) {
  tolower_string(tipo_str);

  if (strcmp(tipo_str, "arvore") == 0) return ARVORE;
  if (strcmp(tipo_str, "lista") == 0) return LIGADA;
  if (strcmp(tipo_str, "hash") == 0) return HASH;

  printf("Tipo de estrutura desconhecido!\nTente as seguintes opções: 'arvore', 'lista', 'hash'\n");
  exit(1);
}

void valida_args(int argc, char *argv[]) {
  	if (argc < 2) {
    printf("Invalido! Insira o caminho do arquivo e o tipo de indice!\n");
    exit(1);
  }

  TIPO = guarda_tipo(argv[2]);
}

void guarda_palavra(char * palavra, int linha) {
  tolower_string(palavra);
  trim(palavra, ".,?:;!");
  
  insere_estrutura(palavra, linha);
}

void carrega_dados(FILE * in, int num_linhas) {
  linhas = cria_lista(num_linhas);

  int contador_linhas = 0;
  char * linha_atual = (char *) malloc((TAMANHO + 1) * sizeof(char));
  char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	

  estrutura = cria_estrutura();

  while (in && fgets(linha_atual, TAMANHO, in)){
    if( (quebra_de_linha = strrchr(linha_atual, '\n')) ) *quebra_de_linha = 0;

    push(linhas, linha_atual);
    copia_ponteiro_linha = linha_atual;

    while ( (palavra = separa_string(&copia_ponteiro_linha, " -/")) ) {
      guarda_palavra(palavra, contador_linhas);
    }

    contador_linhas++;
  }

  free(linha_atual);
  fclose(in);
}

int counting_lines(FILE * f) {
  char c;
  int count = 1;

  // conta cada '\n'
  do {
    c = fgetc(f);
    if (c == '\n') count++;
  } while (c != EOF);

  // volta para o início do arquivo
  rewind(f);

  return count;
}