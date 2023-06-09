#include "Labirinto.h"


int main(){
    int linhas, colunas;
    char opcao;
    Lab *labirinto;
    
    leLabirinto(labirinto, &opcao);
    linhas = labirinto.tamL;
    colunas = labirinto.tamC;
    
    printLab(labirinto);

    desalocaLab(&labirinto);
    return 0;
}
