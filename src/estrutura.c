#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estrutura.h"

const Operacoes ops_estruturas[NUM_ESTRUTURAS] = {
	[ARVORE] = {
		.cria = (FuncaoCria) cria_arvore,
		.insere = (FuncaoInsere) insere_bin,
		.tamanho = (FuncaoTamanho) tamanho_arvore,
		.display = (FuncaoDisplay) display_arvore,
		.imprime = (FuncaoImprime) imprime_arvore,
		.dados = (FuncaoDados) dados_arvore
	},
	[LIGADA] = {
		.cria = (FuncaoCria) cria_lista_ligada_char,
		.tamanho = (FuncaoTamanho) tamanho_lista_ligada_char,
		.display = (FuncaoDisplay) display_ligada_char,
		.imprime = (FuncaoImprime) imprime_ligada_char,
		.insere = (FuncaoInsere) insere_ligada_char,
		.dados = (FuncaoDados) dados_ligada_char
	},
};

void * cria_estrutura() {
	return ops_estruturas[TIPO].cria();
}

int tamanho_estrutura() {
	return ops_estruturas[TIPO].tamanho(estrutura);
}

Boolean insere_estrutura(char * palavra, int linha, int * comparacoes) {
	return ops_estruturas[TIPO].insere(estrutura, palavra, linha, comparacoes);
}

void display_estrutura() {
	ops_estruturas[TIPO].display(estrutura);
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