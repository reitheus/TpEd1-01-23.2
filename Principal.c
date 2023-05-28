#include "Labirinto.h"

int main(){
    int linhas, colunas;
    char opcao;

    leLabirinto(&linhas,&colunas);
    alocaLab(linhas, colunas);
    leEscolha(&opcao);

    
    return 0;
}