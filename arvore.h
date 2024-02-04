#ifndef ARVORE_H
#define ARVORE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define RED 1
#define BLACK 0

typedef struct chave{
    int idade;
    char nome[51];
}Chave;


typedef struct no{
    struct no *pai;
    struct no *esq;
    struct no *dir;
    int cor;
    Chave item;
}No;

typedef No* Arvore;

void alocaArvore(No** );

void liberaArvore(No** );

No* noCria(Chave* );

void le(No** ,int );

void insere (No** ,Chave );

No* balanceamento(No* ,No* );

void printInOrden(No* );

No* rotacaoEsquerda(No* ,No* );

No* rotacaoDireita(No* ,No* );


#endif //arvore.h