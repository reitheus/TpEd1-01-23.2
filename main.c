#include <stdio.h>
#include "labirinto.h"



int main(){
    // int linhas, colunas;
    char opcao='p';
    
     
    Percurso *pTra;
    Posicao *saida = alocaPos();//aloca a posição ára saida
    Posicao *mause = alocaPos();//aloca uma posição para o rato
    Labirinto *pLab;
    pLab = lelabirinto(opcao);

    posMause( pLab, mause);
 
    printf("\n\n");     
    updatePos( saida, pLab->tamL - 2, pLab->tamC -2);
    pTra = alocaPer(pLab->v);
    achaSaida(pLab, saida, mause,pTra,0);
    imprimePercursoNoLabirinto(pLab,pTra);
    
    desalocaPos(&mause); 
    desalocaPos(&saida);
    desalocaPer(&pTra);
    desalocaLab(&pLab);
    return 0;
}
