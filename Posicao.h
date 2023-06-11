#ifndef POSICAO_H
#define POSICAO_H


typedef struct posicao Posicao;

Posicao* alocaPos();
void desalocaPos(Posicao**);
void updatePos(Posicao*, int, int);
int valueX(Posicao*);
int valueY(Posicao*);

#endif // POSICAO_H
