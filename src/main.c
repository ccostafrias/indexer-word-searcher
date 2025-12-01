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

ListaSequencial * listaComandos;
ListaSequencial * linhas;
int num_linhas;
TipoEstrutura TIPO;
void * estrutura = NULL;

int main(int argc, char ** argv){
	FILE * in;
  
  valida_args(argc, argv);

  in = abre_arquivo(argv[1]);
  printf(">>>>> Carregando arquivo...\n");
  
  cria_funcoes();
  preenche_comandos();
  num_linhas = counting_lines(in);
  carrega_dados(in, num_linhas);

  #ifdef DEBUG
    imprime_estrutura();
  #endif

  printf("Arquivo: '%s'\n", argv[1]);
  printf("Tipo de indice: '%s'\n", argv[2]);
  printf("Numero de linhas no arquivo: %d\n", num_linhas);
  printf("Total de palavras unicas indexadas: %d\n", tamanho_estrutura(estrutura));
  if (TIPO == ARVORE) 
    printf("Altura da arvore: %d\n", pega_altura(estrutura));
  printf("Numero de comparacoes realizadas para a construcao do indice: XXXXX\n");

  // inicia serie de comandos
  pede_comando();

  // libera na memoria
  destroi_sequencial(linhas);
  destroi_sequencial(listaComandos);

  return 0;
}