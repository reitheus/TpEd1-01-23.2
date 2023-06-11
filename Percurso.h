#ifndef PERCURSO_H
#define PERCURSO_H

typedef struct {
    Pos **trajetos;
    int n;
    int tamTrajeto;
}Per;

Per* alocaPer(int);

void desalocaPer(Per**);
void updatePer(Per*,int,int);

#endif //Percurso.h