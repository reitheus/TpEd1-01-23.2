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
    Lab *newlab = (Lab*) malloc (m * sizeof(Lab));
    for (int i = 0; i < m; i++)
    {
        newlab->mapa=(Lab*) malloc (n * sizeof(Lab));
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
void leLabirinto(int *L,int *C){
    scanf("%d %d",L,C);
}

//faz a leitura da opção de escolha
void leEscolha(char *pOpc){
    scanf("%c",pOpc);
}

//acha a saida do labirinto
void achaSaida(Lab *plab){
    //utilizar recursão
    //teste
    
}

//imprime o labirinto
void imprimePercursoNoLabirinto(Lab *plab){
    
    
}
