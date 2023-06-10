#include "Labirinto.h"


int main(){
   // int linhas, colunas;
    char opcao;
    Lab *labirinto;

    
    labirinto = leLabirinto(&opcao);
   
    
    printLab(labirinto);

    desalocaLab(&labirinto);
    return 0;
}
