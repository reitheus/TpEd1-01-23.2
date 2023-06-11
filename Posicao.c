#include "Posicao.h"

#include <stdlib.h>
#include <stdio.h>


struct posicao{
    int x;
    int y;
};

Pos* alocaPos(){

    Pos *newpos = (Pos*) malloc (sizeof(Pos));

    return newpos; 
}

//desaloca o labirinto
void desalocaPos(Pos **ppos){
    free(*ppos);
}


void updatePos( Pos *posicao, int y, int x){
    posicao->y = y;
    posicao->x = x;
    
}

int valueX(Pos *posicao){
    return posicao->x;

}

int valueY(Pos *posicao){
    return posicao->y;

}




