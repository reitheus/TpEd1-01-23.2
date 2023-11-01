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



