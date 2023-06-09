#include "Labirinto.h"


int main(){
   // int linhas, colunas;
    char opcao;
    Lab *labirinto;

    
    leLabirinto(labirinto, &opcao);
   
    
    //printLab(labirinto);

    desalocaLab(&labirinto);
    return 0;
}
