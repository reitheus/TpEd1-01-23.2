#ifndef LABIRINTO_H
#define LABIRINTO_H

typedef struct labirinto{
    char** mapa;
    int tamL;
    int tamC;
}Labirinto;

Labirinto* alocaLab(int, int);

void desalocaLab(Labirinto**);

Labirinto* leLabirinto(char*);

int verificavazio(Labirinto*);

void printLab(Labirinto*);

void posMause(Labirinto*, Posicao*);

void achaSaida(Labirinto*, Posicao*, Posicao*, Percurso*, int);

void imprimePercursoNoLabirinto(Labirinto*);

#endif // LABIRINTO_H