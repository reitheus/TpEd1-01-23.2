#ifndef LABIRINTO_H
#define LABIRINTO_H
#include "Percurso.h"
#include "Posicao.h"

typedef struct labirinto Lab;

Lab* alocaLab(int ,int );

void desalocaLab(Lab**);

Lab* leLabirinto( char *opcao);

void printLab(Lab *plab);

void posMause(Lab *pLab, Pos *mause);//acha a posição do rato

void achaSaida(Lab *pLab, Pos *saida, Pos *mause);

void imprimePercursoNoLabirinto(Lab*);
#endif //Labirinto.h
