#include <stdio.h>
#include <stdlib.h>

#include "percurso.h"
#include "posicao.h"


Percurso* alocaPer(int x){
    Percurso* newper = (Percurso*)malloc(sizeof(Percurso));
    newper->tamTrajeto = x;
    newper->trajetos = (Posicao**)calloc(newper->tamTrajeto ,sizeof(Posicao**));
    for (int i = 0; i < newper->tamTrajeto; i++)
    {
        newper->trajetos[i] = alocaPos();
    }
    newper->n=0;
    return newper;
}

void updateTra(Percurso *newper, int i, int posy, int posx){
    newper->trajetos[i]->x = posx;
    newper->trajetos[i]->y = posy;
}

void desalocaPer(Percurso** pTra){
    for (int i = (*pTra)->tamTrajeto; i <= 0; i--){
        desalocaPos(&(*pTra)->trajetos[i]);
    }
    free((*pTra)->trajetos);
    free(pTra);
}