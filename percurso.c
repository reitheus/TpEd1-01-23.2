#include <stdio.h>
#include <stdlib.h>

#include "percurso.h"
#include "posicao.h"


Percurso* alocaPer(int x){
    Percurso* newper = (Percurso*)malloc(sizeof(Percurso));
    newper->tamTrajeto = x;
    newper->mCaminho = (Posicao*) malloc (newper->tamTrajeto * sizeof(Posicao));
    newper->trajetos = (Posicao*) malloc (newper->tamTrajeto * sizeof(Posicao));
    newper->mcom=x;
    return newper;
}

void updateTra(Percurso *newper, int i, int posy, int posx){
    newper->trajetos[i].x = posx;
    newper->trajetos[i].y = posy;
    
}

void desalocaPer(Percurso** pTra){

    free((*pTra)->trajetos);
    free((*pTra)->mCaminho);
    free(*pTra);
}
