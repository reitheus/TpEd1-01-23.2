#include "grafo.h"
#include <stdio.h>

int main(){

	int **cidades = NULL, distancia = 0, n, menorvalor = 50000, aux, n2;
	scanf("%d", &n );
	aux = n; 
	n2 = n;
	alocarGrafo(cidades, n);
	leGrafo(cidades, n);
	distancia = encontraCaminho(cidades, n, menorvalor, aux, n2, distancia); 
	imprimeCaminho(cidades,n, distancia); 
	desalocarGrafo(cidades, n);
	
	return 0;
}



