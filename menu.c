#include "arvore.h"
#include <stdio.h>
void menu(){
    do{
            scanf("%c",&op);
            switch (op)
            {
            case 1:
                scanf("%d",&n);
                le(pArvore,n);
                break;
            case 2:
                imprimeArvore(pArvore);
                break;
            case 0:
                break;
            default:
                
                break;
            }
        }while(op != 0);

}