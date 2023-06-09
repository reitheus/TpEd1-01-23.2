#include "Labirinto.h"


int main(){
    int linhas, colunas;
    char opcao;
    Lab *labirinto;
    
    scanf("%i %i", &linhas, &columas);
    
    
    //leLabirinto(labirinto, &opcao);
     labirinto = alocaLab(linhas, colunas);
    
    //printLab(labirinto);

    desalocaLab(&labirinto);
    return 0;
}
