#ifndef POSICAO_H
#define POSICAO_H

typedef struct posicao Pos;

Pos* alocaPos();

void desalocaPos(Pos** );

void updatePos( Pos* , int , int );


#endif //posição.h
