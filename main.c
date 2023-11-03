#include "grafoponderado.h"
#include <stdio.h>

int main(){

	Grafo *pGrafo = NULL;
    int resultado; 
	leGrafo(pGrafo);
    resultado = encontraCaminho(pGrafo,0);
    if(resultado == 0){
        printf("Não achou caminho");
    }else{

	    imprimeCaminho(pGrafo); 
    }
	desalocaGrafo(&pGrafo);
	return 0;
}

/*#include "grafo.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int n, menorvalor = 50000, aux, n2;
    scanf("%d", &n);
    aux = n;
    n2 = n;

    Grafo **cidades = alocarGrafo(n);
    cidades = leGrafo(cidades, n);

    Grafo *d = (Grafo *)malloc(sizeof(int));
    d = 0;

    Grafo *trajeto = (Grafo *)malloc(n*sizeof(int));

    d = encontraCaminho(cidades, n - 1, menorvalor, aux, n2, d, trajeto);
    imprimeCaminho(n, d, trajeto);
    desalocarGrafo(cidades, n);

    free(d);
    free(trajeto);

    return 0;
}*/



