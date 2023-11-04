#include "grafoponderado.h"
#include <stdio.h>
#include <stdlib.h>


//Função de alocação do labirinto com mensagem de erros em caso de erro    
Grafo* alocaGrafo(int n){
    
    Grafo* newgrafo = (Grafo*)malloc(sizeof(Grafo));
    if (newgrafo == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    newgrafo->mapa = (int**)malloc(n * sizeof(int*));
    if (newgrafo->mapa == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++){
        newgrafo->mapa[i] = (int*)malloc(n * sizeof(int));
        if (newgrafo->mapa[i] == NULL){
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }

    newgrafo->caminho = (int*)malloc((n + 1) * sizeof(int));
    newgrafo->distancia = 0;
    return newgrafo;
}

//Função de desaloção do labirinto
void desalocaGrafo(Grafo** pGrafo){

    free((*pGrafo)->caminho);
    for (int i = 0; i < (*pGrafo)->ncity; i++){
    
        free((*pGrafo)->mapa[i]);
    }
    free((*pGrafo)->mapa);
    free(*pGrafo);

}

//Leitura dos dados do labirinto
Grafo* leGrafo(Grafo* pGrafo){

    int n,i,j,k,m;
    i=0;
    m=0;
    scanf("%d",&n);

    pGrafo = alocaGrafo(n);
    pGrafo->ncity = n;
    while (m < (n * n)){
        scanf("%d %d %d",&i,&j,&k);
        pGrafo->mapa[i][j] = k;
        m++;
    }
    return pGrafo;
}

//Função recursiva
int encontraCaminho(Grafo* pGrafo, int city,int aux,int achou){
    
    if(aux >= pGrafo->ncity){
        pGrafo->caminho[aux] = city;
        return 1;
    }else if(aux < pGrafo->ncity){

        pGrafo->caminho[aux] = city;
        city = verificamenor(pGrafo,city,&aux);
        achou = encontraCaminho(pGrafo,city,aux+1,achou);
    }
    
    return achou;
    
}

//Função verifica menor distancia 
int verificamenor(Grafo *pG,int cidade,int *n){
    int aux,proxcidade,j,inicio,aux1;
    aux1 = 0;
    aux = 9999999;
    inicio = pG->mapa[cidade][0];
    //tranca os lugares que ja passou
    for(int i = 0;i < *n+1;i++){
        j = pG->caminho[i];
        pG->mapa[cidade][j] = -1;
    }
    //procura a menor distancia
    for (int i = 0; i < pG->ncity; i++){
        if(pG->mapa[cidade][i] > -1){
            if(pG->mapa[cidade][i] < aux){
                aux = pG->mapa[cidade][i];
                proxcidade = i;
                aux1 = 1;
            }
        }
    }
    //caso final de retornar a cidade inicial
    if (aux1 == 0){
        aux = inicio;
        proxcidade = 0;
    }
    
    pG->distancia = pG->distancia + aux;
    return proxcidade;
}

//Impressão da saida de acordo com a opção de entrada
void imprimeCaminho(Grafo* pGrafo){
    
    for(int i = 0;i < pGrafo->ncity+1;i++){
        printf("%d ",pGrafo->caminho[i]);
    }
    printf("\n%d\n",pGrafo->distancia);

}
