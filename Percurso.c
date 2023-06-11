#include <stdio.h>
#include <stdlib.h>

#include "percurso.h"
#include "posicao.h"

struct percurso{
    Posicao **trajetos;
    int n;
    int tamTrajeto;
};

Percurso* alocaPer(int x){
    Percurso* newper = (Percurso*)malloc(sizeof(Percurso));
    newper->tamTrajeto = x;
    newper->trajetos = (Posicao**)malloc(newper->tamTrajeto * sizeof(Posicao**));
    for (int i = 0; i < newper->tamTrajeto; i++)
    {
        newper->trajetos[i] = alocaPos();
    }
    newper->n = 0;
    return newper;
}

void updateTra(Percurso* pTra, int i, int posy, int posx){
    pTra->trajetos[i]->x = posx;
    pTra->trajetos[i]->y = posy;
    pTra->n += 1;
}

void desalocaPer(Percurso* pTra){
    for (int i = pTra->n - 1; i <= 0; i--){
        desalocaPos(&(pTra->trajetos[i]));
    }
    free(pTra->trajetos);
    free(pTra);
}