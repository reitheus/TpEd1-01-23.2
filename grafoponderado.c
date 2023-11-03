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

    newgrafo->caminho = (int*)malloc(n * sizeof(int));
    newgrafo->distancia = 0;
    newgrafo->ncity = 0;
    printf("Grafo Alocado\n");
    return newgrafo;
}

//Função de desaloção do labirinto
void desalocaGrafo(Grafo** pGrafo){

    free((*pGrafo)->caminho);
    printf("vetor de caminho desalocado\n");
    for (int i = 0; i < (*pGrafo)->ncity; i++){
    
        free((*pGrafo)->mapa[i]);
    }
    free((*pGrafo)->mapa);
    printf("Mapa desalocado\n");
    free(*pGrafo);
    printf("grafo desalocado\n");

}

//Leitura dos dados do labirinto
Grafo* leGrafo(Grafo* pGrafo){

    int n,i,j,k,m;
    i=0;
    scanf("%d",&n);

    pGrafo = alocaGrafo(n);
    pGrafo->ncity = n;
    while (m < (n*n)){
        scanf("%d %d %d",&i,&j,&k);
        pGrafo->mapa[i][j] = k;
        m++;
    }
    return pGrafo;
}

//Função recursiva
int encontraCaminho(Grafo* pGrafo, int city,int aux,int achou){
    
    printf("aux= %d | city= %d\n",aux,city);
    if(aux > pGrafo->ncity){
        printf("entrou\n");
        return 1;
    }
    if(aux < pGrafo->ncity){

        pGrafo->caminho[aux] = city;
        printf("caminho[%d]=%d\n",aux,pGrafo->caminho[aux]);
        city = verificamenor(pGrafo,city,&aux);
        achou = encontraCaminho(pGrafo,city,aux+1,achou);
    }
    
    return achou;
    
}

//Função verifica menor distancia 
int verificamenor(Grafo *pG,int cidade,int *n){
    int aux,aux1,j;
    aux = 9999999;
    for(int i = 0;i < *n+1;i++){
        j = pG->caminho[i];
        printf("j=%d\n",j);
        pG->mapa[cidade][j] = -1;
    }
    for (int i = 0; i < pG->ncity; i++){
        for (int j = 0; j < pG->ncity; j++){
            printf("%d ", pG->mapa[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < pG->ncity; i++){
        if(pG->mapa[cidade][i] > -1){
            if(pG->mapa[cidade][i] < aux){
                aux = pG->mapa[cidade][i];
                aux1 = i;
            }
        }
    }
    pG->distancia = pG->distancia + aux;
    printf("distancia= %d | cidade= %d | n= %d | aux= %d | aux1= %d\n",pG->distancia,cidade,*n,aux,aux1);
    return aux1;
}

//Impressão da saida de acordo com a opção de entrada
void imprimeCaminho(Grafo* pGrafo){
    
    for(int i = 0;i < pGrafo->ncity;i++){
        printf("%d",pGrafo->caminho[i]);
    }
    printf("\n%d",pGrafo->distancia);

}
