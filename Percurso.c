#include "Percurso.h"
#include "Posicao.h"

#include <stdio.h>
#include <stdlib.h>
 
struct percurso{
    Pos **trajeto;
    int n;
};

//alocação de percuso e posicao
Per* alocaLab(int n){

    Per *newpos = (Per*) malloc (sizeof(Per));
    newpos->trajeto = (Pos*) malloc (n * sizeof(Pos*));
    for (int i = 0; i < n; i++){
        newpos->trajeto[i] = alocaPos();
    }
    newpos->n=n;
    return newpos; 
}

//desaloca o labirinto
void desalocaLab(Per **plab){

}
