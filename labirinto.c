#include <stdio.h>
#include <stdlib.h>

#include "labirinto.h"

Labirinto* alocaLab(int L, int C)
{
    Labirinto* newlab = (Labirinto*)malloc(sizeof(Labirinto));
    if (newlab == NULL)
    {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    newlab->mapa = (char**)malloc(L * sizeof(char*));
    if (newlab->mapa == NULL)
    {
        printf("Memoria insuficiente.\n");
        exit(1);
    }

    for (int i = 0; i < L; i++)
    {
        newlab->mapa[i] = (char*)malloc(C * sizeof(char));
        if (newlab->mapa[i] == NULL)
        {
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }
    newlab->tamL = L;
    newlab->tamC = C;
    printf("\nalocou lab\n");
    return newlab;
}

void desalocaLab(Labirinto** pLab)
{
    for (int i = 0; i < (*pLab)->tamL; i++){
    
        free((*pLab)->mapa[i]);
    }
    printf("\ndesalocou vetor mapa\n");
    free((*pLab)->mapa);
    printf("\ndesalocou mapa\n");
    free(*pLab);
    printf("\ndesalocou lab\n");
}
int verificavazio(Labirinto* pLab)
{
    int vazio = 0;
    for (int i = 0; i < pLab->tamL; i++)
    {
        for (int j = 0; j < pLab->tamC; j++)
        {
            if (pLab->mapa[i][j] == ' ')
            {
                vazio += 1;
            }
        }
    }
    pLab->v = vazio;
    return vazio;
}
Labirinto* lelabirinto(char opcao){
    int L, C;
    Labirinto* plab;
    char lixo;

    scanf("%d %d", &L, &C);
    C += 1;
    scanf("%c", &lixo);
    scanf("%c", &opcao);

    plab = alocaLab(L, C);

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%c", &(plab->mapa[i][j]));
        }
    }
    plab->v = verificavazio(plab);
    plab->op = opcao;
    printf("terminou leitrura.\n");
    return plab;
}



void printLab(Labirinto* pLab)
{
    for (int i = 0; i < pLab->tamL; i++)
    {
        for (int j = 0; j < pLab->tamC; j++)
        {
            printf("%c", pLab->mapa[i][j]);
        }
    }
}

void posMause(Labirinto* pLab, Posicao* mause)
{
    for (int i = 0; i < pLab->tamL; i++)
    {
        for (int j = 0; j < pLab->tamC; j++)
        {
            if (pLab->mapa[i][j] == 'M' || pLab->mapa[i][j] == 'm')
            {
                printf("\n posição mause L %i C %i \n", i, j);
                updatePos(mause, i, j);
            }
        }
    }
}

int achaSaida(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, int i, Posicao *inicio)
{   
    int achou = 0;//se 0 não achou saida se 1 achou saida
    
    if (valueY(mause) == valueY(saida) && valueX(mause) == valueX(saida)){
        printf("achou\n");
        printf("%d\n",i);
        if(i<pTra->mcom){
            pTra->mcom = i;
            printf("é menor\n");
            for(int j=0;j < pTra->mcom;j++){
            *pTra->mCaminho[j] = *pTra->trajetos[j];
            }
        }
        return 1;//se o rato acha a saida retorna 1
    }
    pLab->mapa[valueY(mause)][valueX(mause)] = 'b';
    
    //teste para cima
    if (valueY(mause) - 1 > 0 && valueY(mause) - 1 < pLab->tamL && pLab->mapa[valueY(mause) - 1][valueX(mause)] == ' '){
        
        updatePos(mause, valueY(mause) - 1, valueX(mause));
        
        pTra->n += 1;
        achou = achaSaida(pLab, saida, mause, pTra, i+1);
        updatePos(mause, valueY(mause) + 1, valueX(mause));
        

    }
    
    //teste para baixo
    if (valueY(mause) + 1 > 0 && valueY(mause) + 1 < pLab->tamL && pLab->mapa[valueY(mause) + 1][valueX(mause)] == ' '){

        updatePos(mause, valueY(mause) + 1, valueX(mause));
        updateTra(pTra,pTra->n,valueX(mause),valueY(mause));
        pTra->n += 1;
        achou = achaSaida(pLab, saida, mause, pTra, i + 1);
        updatePos(mause, valueY(mause) - 1, valueX(mause));
        
    }
    
    //teste para direita
    if (valueX(mause) + 1 > 0 && valueX(mause) + 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) + 1] == ' '){

        updatePos(mause, valueY(mause), valueX(mause) + 1);
        updateTra(pTra,pTra->n,valueX(mause),valueY(mause));
        pTra->n += 1;
        achou = achaSaida(pLab, saida, mause, pTra, i + 1);
        updatePos(mause, valueY(mause), valueX(mause) - 1);
        

    }

    
    //teste para esquerda
    if (valueX(mause) - 1 > 0 && valueX(mause) - 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) - 1] == ' '){   
        
        updatePos(mause, valueY(mause), valueX(mause) - 1);
        updateTra(pTra,pTra->n,valueX(mause),valueY(mause));
        pTra->n += 1;
        achou = achaSaida(pLab, saida, mause, pTra, i + 1);
        updatePos(mause, valueY(mause), valueX(mause) + 1);
        
    }
    

    pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
    
    if( valueX(inicio) == valueX(mause) && valueY(inicio) == valueY(mause) && achou == 0){
        printf("Epic Fail");
        return achou;
    }
    
    return achou;
}

Labirinto* imprimepercursoNolabirinto(Labirinto *plab,Percurso *pTra){

    if(plab->op == 'p' || plab->op == 'p'){
        for (int i = 0; i <= pTra->mcom; i++){
            Posicao *pos = pTra->mCaminho[i];
            plab->mapa[pos->x][pos->y] = '.';
            
        }
        printf("%d\n",pTra->mcom);
        printLab(plab);
        
    }else if(plab->op == 'c' || plab->op == 'C'){
        printf("%d\n",pTra->mcom);
        for(int i = 0;i <= pTra->mcom;i++){
            
            printf("%d, %d",pTra->mCaminho[i]->y,pTra->mCaminho[i]->x);
        }
        
    }
    return plab;
}
