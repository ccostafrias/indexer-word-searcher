#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estrutura.h"
#include "lista_ligada.h"
#include "arvore_binaria.h"

// TODO: mudar isso aqui (muito if feio demais)

int tamanho_estrutura() {
  if (strcmp(TIPO_INDICE, "arvore") == 0) {
    return tamanho_arvore(estrutura);

  } else if (strcmp(TIPO_INDICE, "lista") == 0) {
    // return tamanho_lista(estrutura);
  }

  return -1;
}

void cria_estrutura() {
	if (strcmp(TIPO_INDICE, "arvore") == 0) {
    estrutura = cria_arvore();
  } else if (strcmp(TIPO_INDICE, "lista") == 0) {
    estrutura = cria_lista_ligada();
  }
}

void insere_estrutura(char * palavra, int linha) {
	if (strcmp(TIPO_INDICE, "arvore") == 0) {
    insere_bin(estrutura, palavra, linha);
  } else if (strcmp(TIPO_INDICE, "lista") == 0) {
    insere_ligada(estrutura, palavra);
  }
}

void imprime_estrutura() {
	if (strcmp(TIPO_INDICE, "arvore") == 0) {
		display(estrutura);
	} else if (strcmp(TIPO_INDICE, "lista") == 0) {
		imprime_ligada(estrutura);
	}
}

void pega_dados_estrutura(char * palavra, int * ocorrencias, int * comparacoes) {
	if (strcmp(TIPO_INDICE, "arvore") == 0) {
		// TODO: enviar comparacoes como ponteiro para busca
		NoBin * node = busca_bin(estrutura, palavra, comparacoes);

		if (node) {
			*ocorrencias = node->quantidade;
		}
		
	} else if (strcmp(TIPO_INDICE, "lista") == 0) {
		// lógica para tipo LISTA
	}
}