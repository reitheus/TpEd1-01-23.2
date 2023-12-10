#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista *alocaLista(){

    Lista *plista = (Lista *)malloc(sizeof(Lista));
    if (plista != NULL) {
        plista ->pCabeca = NULL;
        plista ->pUltimo = NULL;
        printf("Lista criada\n");
    } else {
        printf("Falha ao alocar memória para a lista\n");
    }
    return plista;
}

bool TLista_EhVazia(Lista *plista ) {
    return (plista->pCabeca == plista->pUltimo);
}

bool insereLista(Lista *plista, Item x) {
    if (plista == NULL) {
        printf("Lista não inicializada\n");
        return true; // Se a lista não foi inicializada, não é possível inserir um item
    }

    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
    if (novaCelula == NULL) {
        printf("Falha ao alocar memória para a célula\n");
        return 0; // Se a alocação falhar, retorna 0 indicando erro na inserção
    }

    novaCelula->pItem = x; // pensar em quais informações estão sendo passadas e de que forma
    novaCelula->prox = NULL;

    if (TLista_EhVazia(plista)) {
        plista->pCabeca->prox = novaCelula;
    } 
    else {
        plista->pUltimo->prox = novaCelula;
    }

    plista->pUltimo = novaCelula;
    printf("Inseriu\n");
    return false;
}

// Função para liberar a memória da lista
void desalocaLista(Lista **plista ) {
    Celula *atual = (*plista )->pCabeca;
    while (atual != NULL) {
        Celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(*plista);
    plista  = NULL;
    printf("Lista desalocada\n");
}

//Remove Lista
//void removeLista(Lista* listaC, Item x );
