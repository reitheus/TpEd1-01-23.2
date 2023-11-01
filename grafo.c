#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

//funções da biblioteca 

//função que aloca memória dinamicamente para receber os dados das cidades de acordo com o número de cidades informado 
int **alocarGrafo(int **cidades, int n){
	
	cidades = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        cidades[i] = (int *)malloc(n * sizeof(int));
    }
    
	return cidades; 
}

//função libera memória alocada 
int** desalocarGrafo(int **cidades, int n){

	for (int i = 0; i < n; i++) {
        free(cidades[i]);
    }
    free(*cidades);

	return cidades;
} 

//função para ler os dados de entrada fornecidos pelo usuário 
int **leGrafo(int **cidades, int n){

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
		scanf("%d ", &cidades[i][j]);
	}

	return cidades; 
}

//função recursiva que retorna o menor caminho
int encontraCaminho(int **cidade, int n, int menorvalor, int aux, int n2, int distancia) {

	if (n == -1) {
        return distancia; 
    }
    
    if (aux == n) {
        return encontraCaminho(cidade, n, menorvalor, aux-1, n2, distancia);
    }
    
    if (aux < n) {	
        if (menorvalor > cidade[n][aux]) {
            menorvalor = cidade[n][aux];
        }
        return encontraCaminho(cidade, n, menorvalor, aux-1, n2, distancia);
    }
    
    if (aux == 0) {	
        if (menorvalor > cidade[n][aux]) {
            menorvalor = cidade[n][aux];
        }
        distancia += menorvalor;
		printf("%d ", n);
        aux = n2;
		menorvalor = 50000;
        return encontraCaminho(cidade, n - 1, menorvalor, aux, n2, distancia); 
    } 
	return distancia;	
}
//imprime menor caminho e a distância percorrida 
void imprimeCaminho(int **cidades, int n, int distancia){
	
	//for(int i = 0; i < n; i++){
	//	for(int j = 0; j < n; j++){
	//		printf("%d", i );
	//	}
	
	printf("\n%d", distancia );
}







