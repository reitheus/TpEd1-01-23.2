#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct labirinto Lab;

Lab* alocaLab(int ,int );

void desalocaLab(Lab**);

void leLabirinto(int* ,int* );

void leEscolha(char* );

void achaSaida(Lab*);

void imprimePercursoNoLabirinto(Lab*);
#endif //Labirinto.h