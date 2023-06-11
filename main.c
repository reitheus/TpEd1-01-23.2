#include "labirinto.h"
#include "percurso.h"
#include "posicao.h"


int main(){
    // int linhas, colunas;
    char opcao;
    int v;
    Labirinto *tabuleiro;
    Posicao *saida, *mause;
    Percurso *pTra;
    saida = alocaPos();//aloca a posição ára saida
    mause = alocaPos();//aloca uma posição para o rato

    tabuleiro = leLabirinto(&opcao);
    v = verificavazio(tabuleiro);
    pTra = alocaPer(v);

    updatePos( saida, tabuleiro->tamL - 2, tabuleiro->tamC - 2);
 
    printLab(tabuleiro);
    

    posMause( tabuleiro, mause);
      
    achaSaida(tabuleiro, saida, mause,pTra,0);
    
    desalocaPos(&mause); 
    desalocaPos(&saida);
    desalocaPer(&pTra);
    desalocaLab(&tabuleiro);
    return 0;
}
