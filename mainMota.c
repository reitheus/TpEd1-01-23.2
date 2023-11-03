#include "grafoponderado.h"
#include <stdio.h>

int main(){

	Grafo *pGrafo = NULL;
    int resultado;
	pGrafo = leGrafo(pGrafo);
    resultado = encontraCaminho(pGrafo,0,0,0);
    if(resultado == 0){
        printf("Não achou caminho");
    }else{

	    imprimeCaminho(pGrafo); 
    }
	desalocaGrafo(&pGrafo);
	return 0;
}



