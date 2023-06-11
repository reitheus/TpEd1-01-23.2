#ifndef POSICAO_H
#define POSICAO_H

typedef struct posicao Pos;

Pos* alocaPos();

void desalocaPos(Pos** );

void updatePos( Pos* , int , int );

int valueX(Pos*);//retorna o valor de X da struct posição

int valueY(Pos*);//retorna o valor de Y da struct posição

#endif //posição.h
