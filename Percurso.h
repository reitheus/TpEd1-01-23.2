#ifndef PERCURSO_H
#define PERCURSO_H

typedef struct percurso Percurso;

Percurso* alocaPer(int );
void desalocaPer(Percurso* );
void updateTra(Percurso* , int, int, int);

#endif // PERCURSO_H