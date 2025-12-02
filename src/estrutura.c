#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estrutura.h"
#include "lista_ligada_char.h"
#include "arvore_binaria.h"
#include "lista_sequencial.h"

Operacoes ops_estruturas[NUM_ESTRUTURAS];

void cria_funcoes() {
	// ARVORE
	ops_estruturas[ARVORE].cria =    (FuncaoCria) cria_arvore;
	ops_estruturas[ARVORE].insere =  (FuncaoInsere) insere_bin;
	ops_estruturas[ARVORE].tamanho = (FuncaoTamanho) tamanho_arvore;
	ops_estruturas[ARVORE].imprime = (FuncaoImprime) display_arvore;
	ops_estruturas[ARVORE].dados =   (FuncaoDados) dados_arvore;

	// LISTA LIGADA
	ops_estruturas[LIGADA].cria =    (FuncaoCria) cria_lista_ligada_char;
	ops_estruturas[LIGADA].tamanho = (FuncaoTamanho) tamanho_lista_ligada_char;
	ops_estruturas[LIGADA].imprime = (FuncaoImprime) imprime_ligada_char;
	ops_estruturas[LIGADA].insere =  (FuncaoInsere) insere_ligada_char;
	ops_estruturas[LIGADA].dados =   (FuncaoDados) dados_ligada_char;
	
	// HASH
}

void * cria_estrutura() {
	return ops_estruturas[TIPO].cria();
}

int tamanho_estrutura() {
	return ops_estruturas[TIPO].tamanho(estrutura);
}

Boolean insere_estrutura(char * palavra, int linha, int * comparacoes) {
	return ops_estruturas[TIPO].insere(estrutura, palavra, linha, comparacoes);
}

void imprime_estrutura() {
	ops_estruturas[TIPO].imprime(estrutura);
}

void pega_dados_estrutura(char * palavra, int * ocorrencias, int * comparacoes, ListaLigadaInt ** indiceLinhas) {
	ops_estruturas[TIPO].dados(estrutura, palavra, ocorrencias, comparacoes, indiceLinhas);
}

void imprime_linhas(ListaLigadaInt * linhasNum) {
	NoInt * p = linhasNum->primeiro;

	for (int i = 0; i < linhasNum->tamanho; i++) {
		printf("%05d: ", p->valor+1);
		imprime_indice(linhas, p->valor);
		p = p->proximo;
	}
}