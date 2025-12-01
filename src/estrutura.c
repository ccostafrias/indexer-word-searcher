#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estrutura.h"
#include "lista_ligada_char.h"
#include "arvore_binaria.h"

Operacoes ops_estruturas[NUM_ESTRUTURAS];

void cria_funcoes() {
	// ARVORE
	ops_estruturas[ARVORE].cria =    cria_arvore;
	ops_estruturas[ARVORE].insere =  insere_bin;
	ops_estruturas[ARVORE].tamanho = tamanho_arvore;
	ops_estruturas[ARVORE].imprime = display_arvore;
	ops_estruturas[ARVORE].dados =   dados_arvore;

	// LISTA LIGADA
	ops_estruturas[LIGADA].cria =    cria_lista_ligada_char;
	ops_estruturas[LIGADA].tamanho = tamanho_lista_ligada_char;
	ops_estruturas[LIGADA].imprime = imprime_ligada_char;
	ops_estruturas[LIGADA].insere =  insere_ligada_char;
	ops_estruturas[LIGADA].dados =  dados_ligada_char;
	
	// HASH
}

void * cria_estrutura() {
	return ops_estruturas[TIPO].cria();
}

int tamanho_estrutura() {
	return ops_estruturas[TIPO].tamanho(estrutura);
}

Boolean insere_estrutura(char * palavra, int linha) {
	return ops_estruturas[TIPO].insere(estrutura, palavra, linha);
}

void imprime_estrutura() {
	ops_estruturas[TIPO].imprime(estrutura);
}

void pega_dados_estrutura(char * palavra, int * ocorrencias, int * comparacoes) {
	ops_estruturas[TIPO].dados(estrutura, palavra, ocorrencias, comparacoes);
}