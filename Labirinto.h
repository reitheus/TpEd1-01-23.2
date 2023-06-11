#ifndef LABIRINTO_H
#define LABIRINTO_H
#include "Percurso.h"
#include "Posicao.h"

typedef struct {
    char **mapa;
    int tamL;
    int tamC;
}Lab;

Lab* alocaLab(int ,int );

void desalocaLab(Lab**);

Lab* leLabirinto(char*);

void printLab(Lab*);

void posMause(Lab*, Pos*);//acha a posição do rato

void achaSaida(Lab*, Pos*, Pos*);

void imprimePercursoNoLabirinto(Lab*);
#endif //Labirinto.h
