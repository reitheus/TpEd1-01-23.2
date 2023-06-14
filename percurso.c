#include <stdio.h>
#include <stdlib.h>

#include "percurso.h"
#include "posicao.h"


Percurso* alocaPer(int x){
    Percurso* newper = (Percurso*)malloc(sizeof(Percurso));
    newper->tamTrajeto = x;
    newper->mCaminho = (Posicao**) malloc (newper->tamTrajeto * sizeof(Posicao*));
    newper->trajetos = (Posicao**) malloc (newper->tamTrajeto * sizeof(Posicao*));
    for (int i = 0; i < newper->tamTrajeto; i++)
    {
        newper->trajetos[i] = alocaPos();
        
    }
    for (int i = 0; i < newper->tamTrajeto; i++)
    {
        newper->mCaminho[i] = alocaPos();
        
    }
    
    newper->n=0;
    newper->mcom=x;
    printf("\nalocou per\n");
    return newper;
}

void updateTra(Percurso *newper, int i, int posy, int posx){
    newper->trajetos[i]->x = posx;
    newper->trajetos[i]->y = posy;
    printf("atualizou vetor tra\n");
    
}

void desalocaPer(Percurso** pTra){
    for (int i = (*pTra)->tamTrajeto; i <= 0; i--){
        desalocaPos(&(*pTra)->trajetos[i]);
        desalocaPos(&(*pTra)->mCaminho[i]);
    }
    printf("\ndesalocou vetor tra\n");
    free((*pTra)->trajetos);
    free((*pTra)->mCaminho);
    printf("\ndesalocou tra\n");
    free(*pTra);
    printf("\ndesalocou per\n");
}
