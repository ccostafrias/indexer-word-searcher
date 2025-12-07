#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "lista_sequencial.h"
#include "comandos.h"
#include "utils.h"
#include "file.h"
#include "lista_ligada_char.h"
#include "arvore_binaria.h"
#include "estrutura.h"

#define DEBUG

ListaSequencial * linhas;
TipoEstrutura TIPO;
void * estrutura = NULL;

int main(int argc, char ** argv){
	FILE * in;
  
  valida_args(argc, argv);

  in = abre_arquivo(argv[1]);
  printf(">>>>> Carregando arquivo...\n---------------------------\n");
  
  int num_linhas = counting_lines(in);
  int comparacoes = 0;
  carrega_dados(in, num_linhas, &comparacoes);

  #ifdef DEBUG
    display_estrutura();
  #endif

  // imprime dados principais da estrutura
  printf("Arquivo: '%s'\n", argv[1]);
  printf("Tipo de indice: '%s'\n", argv[2]);
  printf("Numero de linhas no arquivo: %d\n", num_linhas);
  printf("Total de palavras unicas indexadas: %d\n", tamanho_estrutura(estrutura));
  if (TIPO == ARVORE) 
    printf("Altura da arvore: %d\n", pega_altura(estrutura));
  printf("Numero de comparacoes realizadas para a construcao do indice: %d\n", comparacoes);

  // inicia serie de comandos
  pede_comando();

  // libera na memoria
  destroi_sequencial(linhas);

  return 0;
}