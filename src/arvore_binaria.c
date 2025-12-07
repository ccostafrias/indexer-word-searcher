#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "utils.h"
#include "arvore_binaria.h"

int balanco(NoBin * no);

// =====================
//  == DEBUG
// =====================

#define ROWS 220
#define COLS 800

int display_rec(char ** buffer, NoBin * no, int level, double h_position){

	char * ptr;
	int i, col, a, b;
	double offset;

	if(no){
		col = (int)(h_position * COLS);
		offset = 1.0 / pow(2, level + 2);

		ptr = buffer[1 + level * 3] + col;
		sprintf(ptr, "%s (%d)", no->valor, no->quantidade);
		*(ptr + strlen(ptr)) = ' ';

		if(no->esq || no->dir) *(buffer[2 + level * 3] + col + 1) = '|';

		if(no->esq){
		
			i = (int)((h_position - offset) * COLS);
			*(buffer[3 + level * 3] + 1 + i) = '|';
			i++;
			for(; i <= col; i++) *(buffer[3 + level * 3] + 1 + i) = '-';
		}
		
		if(no->dir){

			for(i = col; i < (int)((h_position + offset) * COLS); i++) *(buffer[3 + level * 3] + 1 + i) = '-';
			*(buffer[3 + level * 3] + 1 + i) = '|';
		}

		a = display_rec(buffer, no->esq, level + 1, h_position - offset);
		b = display_rec(buffer, no->dir, level + 1, h_position + offset);

		if(a > b) return a;
		return b;
	}

	return level;
}

void display_no(NoBin * no, FILE * fp){

	int i, j, r;

	char ** buffer = (char **) malloc(ROWS * sizeof(char *));

	for(i = 0; i < ROWS; i++) {

		buffer[i] = (char *) malloc((COLS + 1) * sizeof(char));

		for(j = 0; j < COLS; j++) buffer[i][j] = ' ';
		buffer[i][j] = '\0';
	}

	r = display_rec(buffer, no, 0, 0.5);

	for(i = 0; i < 3 * r; i++) fprintf(fp, "%s\n", buffer[i]);
}

void display_arvore(Arvore * arvore) {
	FILE *fp = fopen("build/arvore.out", "w");
	display_no(arvore->raiz, fp);
	fclose(fp);
}

// =====================
// == PRINCIPAL
// =====================

Arvore * cria_arvore() {

	Arvore * arvore = (Arvore *) malloc (sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->len = 0;

	return arvore;
}

void imprime_rec(NoBin * no) {
	// percurso in-ordem para a impressão dos elementos

	if (no){
		imprime_rec(no->esq);
		printf("| altura: %03d | %-16s | qtd: %02d |\n", no->h, no->valor, no->quantidade);
		imprime_rec(no->dir);
	}
}

void imprime_arvore(Arvore * arvore) {

	printf("Elementos na arvore:\n");
	imprime_rec(arvore->raiz);
	printf("\n");
}

NoBin * busca_bin_rec(NoBin * no, Elemento e, int * comparacoes) {
	if (!no) return NULL;
	
	(*comparacoes)++;
	if (strcmp(no->valor, e) == 0) {
		return no;
	}

	(*comparacoes)++;
	if (strcmp(no->valor, e) > 0) {
		return busca_bin_rec(no->esq, e, comparacoes);
	}

	return busca_bin_rec(no->dir, e, comparacoes);

}

NoBin * busca_bin(Arvore * arvore, Elemento e, int * comparacoes){
	return busca_bin_rec(arvore->raiz, e, comparacoes);	
}

int balanco(NoBin * no) {

	if(no->esq && no->dir) return (no->dir->h) - (no->esq->h);
	if(no->esq) return -1 * (no->esq->h + 1);
	if(no->dir) return no->dir->h + 1;
	return 0;
}

void atualiza_altura(NoBin * no){
	// assuminos que todos os nós na (sub)arvore definida por 'no' já estão com suas alturas atualizadas.

	if(no->esq && no->dir) no->h = max(no->esq->h, no->dir->h) + 1;
	else if(no->dir) no->h = no->dir->h + 1;
	else if(no->esq) no->h = no->esq->h + 1;
	else no->h = 0;
}

int pega_altura(Arvore * arvore) {
	return arvore->raiz->h;
}

int tamanho_arvore(Arvore * arvore) {
	return arvore->len;
}

NoBin * rotacaoL(NoBin * p){

	NoBin * v;
	NoBin * u = p->esq;
		
	if (balanco(u) == -1) { // rotação LL

		p->esq = u->dir;
		u->dir = p;
		p->h -= 2;
		return u;
	}
	else if (balanco(u) == 1) { // rotação LR
	
		v = u->dir;

		u->dir = v->esq;
		v->esq = u;
		p->esq = v->dir;
		v->dir = p;

		p->h -= 2;
		u->h -= 1;
		v->h += 1;

		return v;
	}

	return NULL;
}

NoBin * rotacaoR(NoBin * p){

	NoBin * v;
	NoBin * u = p->dir;
		
	if (balanco(u) == 1) { // rotação RR

		p->dir = u->esq;
		u->esq = p;
		p->h -= 2;
		return u;
	}
	else if (balanco(u) == -1) { // rotação RL
	
		v = u->esq;

		u->esq = v->dir;
		v->dir = u;
		p->dir = v->esq;
		v->esq = p;

		p->h -= 2;
		u->h -= 1;
		v->h += 1;

		return v;
	}

	return NULL;
}

Boolean insere_AVL_rec(Arvore * arvore, NoBin * raiz, NoBin * pai, NoBin * novo, int linha, int * comparacoes) {
	Boolean r;
	NoBin ** prox;

	(*comparacoes)++;
	if (strcmp(novo->valor, raiz->valor) == 0) {
		raiz->quantidade++;
		insere_ligada_int(raiz->linhas_texto, linha);
		free(novo);

		return FALSE;
	}

	(*comparacoes)++;
	if (strcmp(novo->valor, raiz->valor) < 0) {
		prox = &raiz->esq;
	} else {
		prox = &raiz->dir;
	}

	if (*prox) {
		r = insere_AVL_rec(arvore, *prox, raiz, novo, linha, comparacoes);
		atualiza_altura(raiz);
	} else {
		*prox = novo;
		if (!raiz->dir || !raiz->esq) raiz->h = 1;

		return TRUE;
	}

	int b = balanco(raiz);
	if (abs(b) >= 2){
		NoBin * rot = (b > 0) ? rotacaoR(raiz) : rotacaoL(raiz);

		if (pai){
			if (pai->esq == raiz) pai->esq = rot;
			if (pai->dir == raiz) pai->dir = rot;
		}
		else {
			arvore->raiz = rot;
		}
	}

	return r;
}

Boolean insere_bin(Arvore * arvore, Elemento e, int linha, int * comparacoes){

	NoBin * novo = (NoBin *) malloc(sizeof(NoBin));

	novo->valor = (char *) malloc((strlen(e) + 1) * sizeof(char));
	strcpy(novo->valor, e);

	novo->linhas_texto = cria_lista_ligada_int();
	insere_ligada_int(novo->linhas_texto, linha);

	novo->quantidade = 1;
	novo->h = 0;
	novo->esq = novo->dir = NULL;

	if (arvore->raiz) {
		Boolean inseriu = insere_AVL_rec(arvore, arvore->raiz, NULL, novo, linha, comparacoes);
		if (inseriu) arvore->len++;

		return inseriu;
	}
		
	arvore->raiz = novo;
	arvore->len = 1;
	return TRUE;
}

void dados_arvore(Arvore * arvore, char * palavra, int * ocorrencias, int * comparacoes, ListaLigadaInt ** indiceLinhas) {
	NoBin * node = busca_bin(arvore, palavra, comparacoes);

	if (node) {
		*ocorrencias = node->quantidade;
		*indiceLinhas = node->linhas_texto;
	}
}