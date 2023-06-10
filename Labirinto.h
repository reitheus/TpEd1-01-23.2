#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct labirinto Lab;

Lab* alocaLab(int ,int );

void desalocaLab(Lab**);

Lab* leLabirinto( char *opcao);

void printLab(Lab *plab);

void achaSaida(Lab*);

void imprimePercursoNoLabirinto(Lab*);
#endif //Labirinto.h
