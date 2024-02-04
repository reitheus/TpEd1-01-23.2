#include "arvore.h"
#include <stdio.h>

int main (){

    Arvore pArvore; 
    alocaArvore(&pArvore);
    int op,n;
    do{
        scanf("%d",&op);
        switch (op){
        case 1: // insersão de dados na arvore
            scanf("%d",&n);
            le(&pArvore,n);
            break;
        case 2: // impressão dos dados
            printf("Dados inOrder:\n");
            printInOrden(pArvore);
            break;
        case 0: // encerrado o programa
            break;
        default:// caso de entrado invalida os comando errado
            printf("Selecione umas das opções: 1 - inserir, 2 - imprimir ou 0 - sair");
            printf("\n");
            break;
        }
    }while(op != 0);
    liberaArvore(&pArvore);
    return 0;
}