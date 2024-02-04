#ifndef ARVORE_H
#define ARVORE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct chave{
    char idade;
    char nome[51];
    char dNascimento[11];
}Chave;


typedef struct no{
    struct no *pai;
    struct no *esq;
    struct no *dir;
    int cor;
    Chave item;
}No;

typedef struct No* Arvore;

Arvore alocaArvore();

void liberaArvore(Arvore** );

void le(Arvore* ,char );

void imprimeArvore(Arvore* );

void rotacaoEsquerda(No** ,No* );

void rotacaoDireita(No** ,No* );

#endif //arvore.h