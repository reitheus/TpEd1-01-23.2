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

/*Função de alocação(inicialização) da Árvore;
Passagem de parametros: é ponteiro de ponteiro da raiz, sem retorno pois altera direto o ponteiro da raiz.

Exemplo: alocaArvore(arvore)*/
void alocaArvore(No** );

/*Função de Liberação da memoria dos nos da Árvore e da sua raiz; 
Passagem de parametro: ponteiro de ponteiro do no da arvore. 

Exemplo: liberaArvore(arvore);*/
void liberaArvore(No** );

/*Função de criação de um novo no, apena faz a inicialização não faz a sua inserção; 
Passgem de parametros: variavel do tipo de Chave que será armazenado na arvore.
Retorno: Retorna um Ponteiro do no.

Exemplo: *ppRaiz = noCria(dado);*/
No* noCria(Chave );

/*Função de leitura dos dados a serem armazenados; 
Passagem de parametros: Ponteiro de ponteiro da raiz, inteiro quantidade de inserções a serem feitas

Exemplo: le(arvore,x);*/
void le(No** ,int );

/*Função de rotação da arvore, faz a troca dos nos girando eles para a esquerda; 
Passagem de parametros: Ponteiro de pontiro da Raiz.

Exemplo: rotacaoEsquerda(ppRaiz);*/
void rotacaoEsquerda(No** );

/*Função de rotação da árvore, faz a troca dos nos girando eles para a direita;
Passagem de parametros: Ponteiro de pontiro da Raiz.

Exemplo: rotacaoDireita(ppRaiz);*/
void rotacaoDireita(No** );

/*Função de balanceamento e inserção recursivo, onde trata os caso para a inserção e balanceamento correto da arvore; Passagem de parametro: Ponteiro de ponteiro da raiz, variavel do tipo Chave com os dados.

Exemplo: balanceamento(ppRaiz,dado);*/
void balanceamento(No** ,Chave );

/*Função de verificação da cor do no; 
Passagem de parametro: pontiro do no a ser analisado; 
Retorno: 0 não é vermelho, 1 é vermelho

Exemplo: cor = eh_vermelho(pNo);*/
int eh_vermelho(No* );

/*Função de controle e chamada da função de balanceamento; 
Passagem de parametro: Ponteiro de ponteiro da Raiz, variavel do tipo Chahve onde estão os dados a serem armazenados.

Exemplo: insere(ppRaiz,dado);*/
void insere (No** ,Chave );

/*Função de inverção de cor do no, muda a cor do no para vermelho e coloca seus nos filhos como pretos; 
Passagem de parametro: Ponteiro do no a ser alterado.

Exemplo: inverteCor(pNo);*/
void inverteCor(No* );

/*Função de impressão dos dados da árvore em ordem crescente; 
Passagem de parametro: Ponteiro da Raiz.

Exemplo: printInOrden(*arvore);*/
void printInOrden(No* );

#endif //arvore.h