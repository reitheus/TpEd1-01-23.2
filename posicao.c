#include <stdio.h>
#include <stdlib.h>

#include "posicao.h"

struct posicao{
    int x;
    int y;
};

Posicao* alocaPos(){
    Posicao* newpos = (Posicao*)malloc(sizeof(Posicao));
    printf("\nalocou pos\n");
    return newpos;
}

void desalocaPos(Posicao** ppos){
    free(*ppos);
    printf("\ndesalocou pos\n");
}

void updatePos(Posicao* posicao, int y, int x){
    posicao->y = y;
    posicao->x = x;
}

int valueX(Posicao* posicao){
    return posicao->x;
}

int valueY(Posicao* posicao){
    return posicao->y;
}
