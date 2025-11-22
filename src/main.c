#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "lista_sequencial.h"
#include "comandos.h"
#include "utils.h"
#include "file.h"
#include "lista_ligada.h"
#include "arvore_binaria.h"

#define DEBUG

ListaSequencial * listaComandos;
ListaSequencial * linhas;
int num_linhas;
char TIPO_INDICE[32];
void * estrutura = NULL;

int main(int argc, char ** argv){
	FILE * in;
  
  printf(">>>>> Carregando arquivo...\n");

  valida_args(argc, argv);
  in = abre_arquivo(argv[1]);
  
  preenche_comandos();
  num_linhas = counting_lines(in);
  carrega_dados(in, num_linhas);

  #ifdef DEBUG
    if (strcmp(TIPO_INDICE, "arvore") == 0) {
      display(estrutura);
    } else if (strcmp(TIPO_INDICE, "lista") == 0) {
      imprime_ligada(estrutura);
    }
  #endif

  printf(">>>>> Arquivo carregado!\n");
  printf("Arquivo: '%s'\n", argv[1]);
  printf("Tipo de indice: '%s'\n", argv[2]);
  printf("Numero de linhas no arquivo: %d\n", num_linhas);
  printf("Total de palavras unicas indexadas: XXXXX\n");
  if (strcmp(TIPO_INDICE, "arvore") == 0) 
    printf("Altura da arvore: XXXX\n");
  
  // inicia serie de comandos
  pede_comando();

  // libera na memoria
  destroi_sequencial(linhas);
  destroi_sequencial(listaComandos);

  return 0;
}