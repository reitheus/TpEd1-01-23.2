#include <stdio.h>
#include "labirinto.h"



int main(){
    // int linhas, colunas;
    char opcao=' ';
    
     
    Percurso *pTra;
    Posicao *inicio = alocaPos();
    Posicao *saida = alocaPos();//aloca a posição ára saida
    Posicao *mause = alocaPos();//aloca uma posição para o rato
    Labirinto *pLab;
    int achou = 0;
    pLab = lelabirinto(opcao);

    posMause( pLab, mause);
    updatePos(inicio, valueY(mause), valueX(mause));
    printf("\n");     
    updatePos( saida, pLab->tamL - 2, pLab->tamC -2);
    pTra = alocaPer(pLab->v);
    achaSaida(pLab, saida, mause,pTra,1, inicio, achou);
    pLab = imprimepercursoNolabirinto(pLab,pTra);
    
    desalocaPos(&inicio);
    desalocaPos(&mause); 
    desalocaPos(&saida);
    desalocaPer(&pTra);
    desalocaLab(&pLab);
    return 0;
}
