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
Lab* alocaLab(int L,int C){
    //L = linhas; C = colunas
    Lab *newlab = (Lab*)malloc(sizeof(Lab) );//Alloca um labirinto
    if(newlab == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }
   
    (*newlab).mapa = (char**)malloc(L * sizeof(char*));
    if((*newlab).mapa  == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }
    
    for (int i = 0; i < L; i++){
        
        (*newlab).mapa[i] = (char*)malloc(C * sizeof(char));
        if((*newlab).mapa[i] == NULL){
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }
    newlab->tamL = L;
    newlab->tamC = C;
    return newlab; 
}

//desaloca o labirinto
void desalocaLab(Lab **pLab){
    
    for (int i = 0; i <  (*pLab)->tamL; i++){
        
        free((*pLab)->mapa[i]);
    }
    free( (*pLab)->mapa);
    free(*pLab);
    
}

//le as entradas para o labirinto
Lab* leLabirinto(char *opcao){
    int L, C;
    Lab *plab;
    scanf("%d %d", &L, &C);
    //L++;
    scanf("%c", opcao);
    
    plab = alocaLab(L, C);
    
  
    
    for(int i = 0; i < L ; i++){
        for(int j = 0; j < C; j++){
            //scanf("%c", &(plab->mapa[i][j]));
            fgets(&(plab->mapa[i][j]), 1,stdin);
        }

    }
    //fgets(&(plab->mapa[L - 1][0]), C,stdin);
    
    return plab;
    
}

void printLab(Lab *pLab){// função para testes posteriormente pode ser apagada

   for(int i = 0; i < pLab->tamL; i++){
        for(int j = 0; j < pLab->tamC; j++){
            printf("%c", pLab->mapa[i][j]);
        
        }
       
    }

   // printf("%c",pLab->tamL);
   // printf("%c",pLab->tamC);
    

}

//acha a saida do labirinto
void achaSaida(Lab *pLab){
    //utilizar recursão
    //teste
    
}

//imprime o labirinto
void imprimePercursoNoLabirinto(Lab *pLab){
    
    
}
