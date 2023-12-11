#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

// função para criar a lista
Lista *alocaLista(){

    Lista *plista = (Lista *)malloc(sizeof(Lista));
    if (plista == NULL) {
        printf("Falha ao alocar memória para a lista\n");
    } 
    plista->pCabeca = (Celula*)malloc(sizeof(Celula));
    plista->pCabeca->prox = NULL;
    plista->pUltimo = plista->pCabeca;
    
    return plista;
}

// função que verifica se a lista está vazia 
bool TLista_EhVazia(Lista *plista ) {
    return (plista->pCabeca == plista->pUltimo);
}

//função para inserir itens na lista encadeada 
bool insereLista(Lista *pLista, Item x) {
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    if (nova == NULL)
        return false;
    nova->prox = NULL;
    nova->pItem = x;
    pLista->pUltimo->prox = nova;
    pLista->pUltimo = nova;
    return true;
}

// Função para liberar a memória da lista
void desalocaLista(Lista** plista ) {
    Celula *atual = (*plista)->pCabeca, *aux;
    while (atual != NULL) {
        aux = atual->prox;
        free(atual);
        atual = aux;
    }
    free((*plista));
    *plista  = NULL;
}

// função para ordenar as listas de adjacências 
void ordenaLista(Lista *pLista) {
    Celula *atual = pLista->pCabeca->prox;  // Pular o nó cabeça fictício
    Celula *ordenado = NULL;

    pLista->pCabeca->prox = NULL;  // Resetar a lista original

    while (atual != NULL) {
        Celula *prox = atual->prox;

        if (ordenado == NULL || atual->pItem.distancia < ordenado->pItem.distancia) {
            // Insere no início da lista ordenada
            atual->prox = ordenado;
            ordenado = atual;
        } else {
            // Procura o local adequado na lista ordenada
            Celula *anterior = ordenado;
            while (anterior->prox != NULL && atual->pItem.distancia >= anterior->prox->pItem.distancia) {
                anterior = anterior->prox;
            }
            // Insere na posição correta
            atual->prox = anterior->prox;
            anterior->prox = atual;
        }

        atual = prox;
    }

    // Atualiza a cabeça e o último da lista original
    pLista->pCabeca->prox = ordenado;
    // Ajusta pUltimo para apontar para o último elemento
    while (pLista->pUltimo->prox != NULL) {
        pLista->pUltimo = pLista->pUltimo->prox;
    }
}

// função para imprimir as listas de adjacências ordenadas  
void imprimeOrdenado(Lista* pLista) {
    Celula *aux = pLista->pCabeca->prox;  // Pular o nó cabeça fictício
    while (aux != NULL) {
        printf("(%d, %d) -> ", aux->pItem.cityatual, aux->pItem.distancia);
        aux = aux->prox;
    }
    printf("NULL \n");
}
