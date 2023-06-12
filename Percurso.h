#ifndef PERCURSO_H
#define PERCURSO_H

#include "posicao.h"

typedef struct {
    Posicao **trajetos;
    int n;
    int tamTrajeto;
}Percurso;

Percurso* alocaPer(int );
void desalocaPer(Percurso** );
void updateTra(Percurso* , int, int, int);

#endif // PERCURSO_H