#include "Labirinto.h"
#include "Percurso.h"
#include "Posicao.h"

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
        
        (*newlab).mapa[i] = (char*)malloc( C * sizeof(char));
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
    char lixo;
    scanf("%d %d", &L, &C);
    C += 1;//soma mais pois nos arquivos de testes tem que contar o \n
    //L++;
    scanf("%c", &lixo);//serve para eliminar os \n
    scanf("%c", opcao);//Lê a opção para imprimir
    scanf("%c", &lixo);//serve para eliminar os \n
   // scanf("%c", &lixo);

    plab = alocaLab(L, C);
    
  
    
    for(int i = 0; i < L ; i++){
        for(int j = 0; j < C ; j++){
            scanf("%c", &(plab->mapa[i][j]));
            
        }

    }
    
    plab->mapa[L - 2][C - 2] = 'S';

  
    return plab;
    
}

void printLab(Lab *pLab){// função para testes posteriormente pode ser apagada
   // X = colunas, tamC ; Y = Linhas, tamL
    
   for(int i = 0; i < pLab->tamL; i++){
        for(int j = 0; j < pLab->tamC; j++){
       
            printf("%c", pLab->mapa[i][j]);
            
        }
       
    }

}

//acha a saida do labirinto
void achaSaida(Lab *pLab){
    
    Pos *saida;
    saida = alocaPos();
    updatePos( saida, pLab->tamC, pLab->tamL-1);
    
    
    //utilizar recursão
    //teste
    desalocaPos(&saida);
}

//imprime o labirinto
void imprimePercursoNoLabirinto(Lab *pLab){
    
    
    
}
