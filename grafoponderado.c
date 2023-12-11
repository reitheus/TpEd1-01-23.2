#include "grafoponderado.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


//Função de alocação do labirinto com mensagem de erros em caso de erro    
Grafo* alocaGrafo(int n){
    
    Grafo* newgrafo = (Grafo*)malloc(sizeof(Grafo));
    newgrafo->plista = (Lista**)malloc(n * sizeof(Lista*));
    for (int i = 0; i < n; i++){
        newgrafo->plista[i] = alocaLista();
    }
    newgrafo->pLFinal = alocaLista();
    newgrafo->caminho = (int*)malloc(n * sizeof(int));
    newgrafo->distancia = 0;
    newgrafo->ncity = 0;
    return newgrafo;
}

//Função de desaloção do labirinto
void desalocaGrafo(Grafo** pGrafo){
    
    free((*pGrafo)->caminho);
    desalocaLista(&(*pGrafo)->pLFinal);
    for (int i = 0; i < (*pGrafo)->ncity; i++){
        desalocaLista(&(*pGrafo)->plista[i]);
    }
    free((*pGrafo)->plista);
    free((*pGrafo));

}

//Leitura dos dados do labirinto
Grafo* leGrafo(Grafo* pGrafo){

    int i,n,m,j,k;
    Item aux;
    i=0;
    m=0;
    scanf("%d",&n);

    pGrafo = alocaGrafo(n);
    pGrafo->ncity = n;
    while (m < (n * n)){
        scanf("%d %d %d",&i,&j,&k);
        aux.cityatual = j;
        aux.distancia = k;
        insereLista((*pGrafo).plista[i],aux);
        m++;
    }
    for(int l = 0;l < n;l++){
        ordenaLista(pGrafo->plista[l]);
        printf("Adjacencia do vertices %d:",l);
        imprimeOrdenado(pGrafo->plista[l]);
    }
    return pGrafo;
}

//Função recursiva
int encontraCaminho(Grafo* pGrafo, int city,int aux,int achou){
    Item x;
    x.cityatual = city;
    if(aux >= pGrafo->ncity){
        insereLista(pGrafo->pLFinal,x);
        return 1;
    }else if(aux < pGrafo->ncity){

        insereLista(pGrafo->pLFinal,x);
        city = verificamenor(pGrafo,city,&aux);
        achou = encontraCaminho(pGrafo,city,aux+1,achou);
    }
    return achou;
    
}

//Função verifica menor distancia 
int verificamenor(Grafo *pG,int cidade,int *n){

    Celula *aux = pG->plista[cidade]->pCabeca->prox;
    Celula *aux1 = pG->pLFinal->pCabeca->prox;
    if(*n < pG->ncity-1){

        while(aux1 != NULL){
            if (aux->pItem.cityatual == aux1->pItem.cityatual){
                aux = aux->prox;
            }else if(aux->prox != NULL && aux->pItem.distancia > aux->prox->pItem.distancia){
                aux = aux->prox;
            }else if(aux->prox != NULL && aux->pItem.distancia < aux->prox->pItem.distancia){
                aux1 = aux1->prox;
            }else if(aux->prox == NULL){
                aux1 = aux1->prox;
            }
        }
    }else{
        while(aux != NULL){
            if(aux->pItem.cityatual == 0){
                pG->distancia = pG->distancia + aux->pItem.distancia;
                return aux->pItem.cityatual;
            }
        }
    }
    pG->distancia = pG->distancia + aux->pItem.distancia;
    return aux->pItem.cityatual;
}

//Impressão da saida de acordo com a opção de entrada
void imprimeCaminho(Grafo* pGrafo){
    
    Celula *aux = pGrafo->pLFinal->pCabeca->prox;
    printf("Melhor Distancia: ");
    printf("%d\n",pGrafo->distancia);
    printf("Melhor Caminho: ");
    while(aux != NULL){
        printf("%d ",aux->pItem.cityatual);
        aux = aux->prox;
    }
    printf("\n");

}
