#include "Posicao.h"

#include <stdlib.h>
#include <stdio.h>


struct posicao{
    int x;
    int y;
};

Pos* alocaLab(){

    Pos *newpos = (Pos*) malloc (sizeof(Pos));

    return newpos; 
}

//desaloca o labirinto
void desalocaLab(Pos **ppos){
    free(*ppos);
}
