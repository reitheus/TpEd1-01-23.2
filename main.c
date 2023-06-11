#include "Labirinto.h"
#include "Percurso.h"
#include "Posicao.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    // int linhas, colunas;
    char opcao;
    Lab *labirinto;
    Pos *saida, *mause;
    saida = alocaPos();//aloca a posição ára saida
    mause = alocaPos();//aloca uma posição para o rato

    labirinto = leLabirinto(&opcao);


    updatePos( saida, labirinto->tamL - 2, labirinto->tamC - 2);
 
    printLab(labirinto);
    
    printf("\n\n");
    posMause( labirinto, mause);
    
    achaSaida(labirinto, saida, mause);
    
    desalocaPos(&mause); 
    desalocaPos(&saida); 
    desalocaLab(&labirinto);
    return 0;
}
