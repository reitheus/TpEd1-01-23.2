#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct item{
    int distancia;
    int cityatual;
}Item;

typedef struct celula{
    Item pItem;
    struct celula *prox;  
}Celula;

typedef struct lista{
    Celula *pCabeca;
    Celula *pUltimo;
}Lista;

//Aloca lista
Lista *alocaLista();

//Desalocacão de lista
void desalocaLista(Lista** );

//Inicia lista
bool insereLista(Lista *,Item );

//verifica se a lista é vazia
bool TLista_EhvVazia(Lista *);

//Função de ordenação 
void ordenaLista(Lista* );

//Função imprimi ordenação 
void imprimeOrdenado(Lista* );

#endif//lista.h