#include <stdio.h>
#include <stdlib.h>

#include "grafoponderado.h"

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
    newgrafo->ncity = n;
    newgrafo->distancia = 0;
    return newgrafo;
}

//Função de desaloção do labirinto
void desalocaLab(Grafo** pGrafo){

    free((*pGrafo)->caminho);
    for (int i = 0; i < (*pGrafo)->ncity; i++){
    
        free((*pGrafo)->mapa[i]);
    }
    free((*pGrafo)->mapa);
    free(*pGrafo);

}

//Leitura dos dados do labirinto
Grafo* leGrafo(Grafo* pGrafo){

    int n;

    scanf("%d",&n);

    pGrafo = alocaLab(n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &(pGrafo->mapa[i][j]));
        }
    }

    return pGrafo;
}

//Função recursiva
int encontracaminho(Grafo* pGrafo, int city,int aux){
    
    
    if(city > pGrafo->ncity){
        if
        return 1;
    }
    
    
    
    if () {	
        if (menorvalor > cidade[n][aux]) {
            menorvalor = cidade[n][aux];
        }
        distancia += menorvalor;
		printf("%d ", n);
        aux = n2;
		menorvalor = 50000;
        return encontraCaminho(cidade, n - 1, menorvalor, aux, n2, distancia); 
    } 
    
    return ;
}

//Impressão da saida de acordo com a opção de entrada

Grafo* imprimeCaminho(Grafo* pGrafo){
    
    for(int i = 0;i < pGrafo->ncity;i++);{
        printf("%d",pGrafo->caminho[i]);
    }
    printf("%d",pGrafo->distancia);

    return pGrafo;
}
