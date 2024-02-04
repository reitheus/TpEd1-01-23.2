#include "arvore.h"
#include <stdio.h>

int main (){

    Arvore pArvore; 
    alocaArvore(&pArvore);
    int op,n;
    do{
        scanf("%d",&op);
        switch (op){
        case 1:
            scanf("%d",&n);
            le(&pArvore,n);
            break;
        case 2:
            printInOrden(pArvore);
            break;
        case 0:
            break;
        default:
            printf("selecione umas das opções: 1, 2 ou 0");
            printf("\n");
            break;
        }
    }while(op != 0);
    liberaArvore(&pArvore);
    return 0;
}