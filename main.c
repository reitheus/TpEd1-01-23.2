#include <stdio.h>
#include "labirinto.h"



int main(){
    // int linhas, colunas;
    char opcao='p';
    
     
    Percurso *pTra;
    Posicao *saida = alocaPos();//aloca a posição ára saida
    Posicao *mause = alocaPos();//aloca uma posição para o rato
    Posicao *inicio;
    Labirinto *pLab;
    pLab = lelabirinto(opcao);
    inicio = alocaPos();
    posMause( pLab, mause);
    updatePos(inicio, valueY(mause), valueX(mause));
    printf("\n");     
    updatePos( saida, pLab->tamL - 2, pLab->tamC -2);
    pTra = alocaPer(pLab->v);
    printf("\nentrou recursao\n");
    achaSaida(pLab, saida, mause,pTra,1, inicio);
    printf("\nsaiu recursão\n");
    pLab=imprimepercursoNolabirinto(pLab,pTra);
    
    desalocaPos(&inicio);
    desalocaPos(&mause); 
    desalocaPos(&saida);
    desalocaPer(&pTra);
    desalocaLab(&pLab);
    return 0;
}
