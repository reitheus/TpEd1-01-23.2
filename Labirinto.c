#include "Labirinto.h"
#include "Percurso.h"

#include <stdio.h>
#include <stdlib.h>

struct labirinto{
    char **mapa;
    int tamL;
    int tamC;
};

//alloca o labirtinto
Lab* alocaLab(int n,int m){
    //n = linhas; m = colunas
    Lab *newlab = (Lab*) malloc (sizeof(Lab));//Alloca um labirinto
    
    newlab->mapa = (char*)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++)
    {
        newlab->mapa=(char) malloc (n * sizeof(char));
    }
    newlab->tamL=n;
    newlab->tamC=m;
    return newlab; 
}

//desaloca o labirinto
void desalocaLab(Lab **plab){
     
    for (int i = 0; i < (*plab)->tamL; i++)
    {
        free((*plab)->mapa[i]);
    }
    free((*plab)->mapa);
    free(plab);
    
}

//le as entradas para o labirinto
void leLabirinto(Lab *plab, char *opcao){
    char L, C;
    scanf("%d %d",L,C);
    scanf("%c", saida);
    
    plab = alocaLab(L, C)
    
    
    
    
}



//acha a saida do labirinto
void achaSaida(Lab *plab){
    //utilizar recursão
    //teste
    
}

//imprime o labirinto
void imprimePercursoNoLabirinto(Lab *plab){
    
    
}
