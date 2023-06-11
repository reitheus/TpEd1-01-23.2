#include "Labirinto.h"
#include "Percurso.h"
#include "Posicao.h"

#include <stdio.h>
#include <stdlib.h>



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
    scanf("%c", &lixo);//serve para eliminar os \n
    scanf("%c", opcao);//Lê a opção para imprimir
    scanf("%c", &lixo);//serve para eliminar os \n


    plab = alocaLab(L, C);
    
    for(int i = 0; i < L ; i++){
        for(int j = 0; j < C ; j++){
            scanf("%c", &(plab->mapa[i][j]));   
        }
    }
    //plab->mapa[L - 2][C - 2] = 'S';//Teste para ver a saida
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

//acha a posição do rato no labirinto
void posMause(Lab *pLab, Pos *mause){
    
    for(int i = 0; i < pLab->tamL; i++){
        for(int j = 0; j < pLab->tamC; j++){
       
            if(pLab->mapa[i][j] == 'M' || pLab->mapa[i][j] == 'm'){
                printf("posição mause L %i C %i", i, j);
                updatePos( mause, i, j);
                return;
            }
        }
    }
}

//acha a saida do labirinto
void achaSaida(Lab *pLab, Pos *saida, Pos *mause){
    
    printf("posição atual L %i C %i \n", valueY(mause), valueX(mause));
    
    if(valueY(mause) == valueY(saida) && valueX(mause) == valueX(saida)){
        printf("achou a saida");
        printf("coordenadas atuais L %i C %i", valueY(mause), valueX(mause));    
        
        return;
    }

    //teste para cima
    //se estiver dentro do labirinto e se espaço vazio
    if(valueY(mause) - 1 > 0 && valueY(mause) - 1 <  pLab->tamL && pLab->mapa[valueY(mause) - 1 ][valueX(mause)] == ' '){
        
        pLab->mapa[valueY(mause)][valueX(mause)] = 'b';
        updatePos(mause, valueY(mause) - 1, valueX(mause));        
        achaSaida(pLab, saida, mause);        
        updatePos(mause, valueY(mause) + 1, valueX(mause));
        pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
    
    }
    
    
    //teste para baixo
    //se estiver dentro do labirinto e se espaço vazio
    if(valueY(mause) + 1 > 0 && valueY(mause) + 1 <  pLab->tamL && pLab->mapa[valueY(mause) + 1 ][valueX(mause)] == ' '){
       
        updatePos(mause, valueY(mause) + 1, valueX(mause));
        achaSaida(pLab, saida, mause);
        updatePos(mause, valueY(mause) - 1, valueX(mause));
        pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
    
    }
    
    
    //teste para esquerda
    //se estiver dentro do labirinto e se espaço vazio
    if(valueX(mause) - 1 > 0 && valueX(mause) - 1 <  pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) - 1] == ' '){
        
        updatePos(mause, valueY(mause) , valueX(mause) - 1);
        achaSaida(pLab, saida, mause);
        updatePos(mause, valueY(mause) , valueX(mause) + 1);
        pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
    
    }
    
    //teste para direita
    //se estiver dentro do labirinto e se espaço vazio
    if(valueX(mause) + 1 > 0 && valueX(mause) + 1 <  pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) + 1] == ' '){
        
        updatePos(mause, valueY(mause) , valueX(mause) + 1);
        achaSaida(pLab, saida, mause);
        updatePos(mause, valueY(mause) , valueX(mause) - 1);
        pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
    
    }

    if( !(valueY(mause) == valueY(saida) && valueX(mause) == valueX(saida)) ){
        pLab->mapa[valueY(mause)][valueX(mause)] = 'x';//atribui x para os locais que o rato já passou e não teve saida
        return;
    
    }   
}

//imprime o labirinto
void imprimePercursoNoLabirinto(Lab *pLab){
    
    
    
}
