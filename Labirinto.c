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
    return newlab;
}

void desalocaLab(Labirinto** pLab)
{
    for (int i = 0; i < (*pLab)->tamL; i++)
    {
        free((*pLab)->mapa[i]);
    }
    free((*pLab)->mapa);
    free(*pLab);
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
    scanf("%c", &lixo);

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
                //printf("\n posição mause L %i C %i \n", i, j);
                updatePos(mause, i, j);
            }
        }
    }
}

void achaSaida(Labirinto* pLab, Posicao *saida, Posicao *mause, Percurso *pTra, int i)
{
    //printf("posição atual L %i C %i \n", valueY(mause), valueX(mause));

    if (valueY(mause) == valueY(saida) && valueX(mause) == valueX(saida))
    {
        imprimePercursoNoLabirinto(pLab,pTra);

        return;
    }
    else{
        do
        {
            if (valueY(mause) - 1 > 0 && valueY(mause) - 1 < pLab->tamL && pLab->mapa[valueY(mause) - 1][valueX(mause)] == ' ')
            {
                pLab->mapa[valueY(mause)][valueX(mause)] = 'b';
                updateTra(pTra, i, valueY(mause) - 1, valueX(mause));
                updatePos(mause, valueY(mause) - 1, valueX(mause));
                i = i + 1;
                achaSaida(pLab, saida, mause, pTra, i);
                updatePos(mause, valueY(mause) + 1, valueX(mause));
                pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
            }

            if (valueY(mause) + 1 > 0 && valueY(mause) + 1 < pLab->tamL && pLab->mapa[valueY(mause) + 1][valueX(mause)] == ' ')
            {
                pLab->mapa[valueY(mause)][valueX(mause)] = 'b';
                updateTra(pTra, i, valueY(mause) - 1, valueX(mause));
                updatePos(mause, valueY(mause) + 1, valueX(mause));
                i = i + 1;
                achaSaida(pLab, saida, mause, pTra, i);
                updatePos(mause, valueY(mause) - 1, valueX(mause));
                pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
            }

            if (valueX(mause) - 1 > 0 && valueX(mause) - 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) - 1] == ' ')
            {
                pLab->mapa[valueY(mause)][valueX(mause)] = 'b';
                updateTra(pTra, i, valueY(mause) - 1, valueX(mause));
                updatePos(mause, valueY(mause), valueX(mause) - 1);
                i = i + 1;
                achaSaida(pLab, saida, mause, pTra, i);
                updatePos(mause, valueY(mause), valueX(mause) + 1);
                pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
            }

            if (valueX(mause) + 1 > 0 && valueX(mause) + 1 < pLab->tamC && pLab->mapa[valueY(mause)][valueX(mause) + 1] == ' ')
            {
                pLab->mapa[valueY(mause)][valueX(mause)] = 'b';
                updateTra(pTra, i, valueY(mause) - 1, valueX(mause));
                updatePos(mause, valueY(mause), valueX(mause) + 1);
                i = i + 1;
                achaSaida(pLab, saida, mause, pTra, i);
                updatePos(mause, valueY(mause), valueX(mause) - 1);
                pLab->mapa[valueY(mause)][valueX(mause)] = ' ';
            }

            if (!(valueY(mause) == valueY(saida) && valueX(mause) == valueX(saida)))
            {
                pLab->mapa[valueY(mause)][valueX(mause)] = 'x';
                return;
            }


        } while (i < pLab->v);
    }
}

void imprimePercursoNoLabirinto(Labirinto* pLab,Percurso *pTra){

    if(pLab->op == 'p' || pLab->op == 'p'){
        for (int i = 0; i < pLab->tamL; i++){
            for (int j = 0; i < pLab->tamC; i++){

                if(pLab->mapa[i][j] == 'x'){
                    pLab->mapa[i][j] = ' ';
                    return;
                }else if(pLab->mapa[i][j] == 'b'){
                    pLab->mapa[i][j] = '.';
                    return;
                }else{
                    return;
                }
            }
            
            
        }
        printf("achou a saida");
        printf("%d",pTra->n);
        printLab(pLab);
    }
    if(pLab->op == 'c' || pLab->op == 'C'){
        printf("%d\n",pTra->n);
        for(int i=0;i<pTra->n;i++){
            printf("%d, %d\n",pTra->trajetos[i]->x,pTra->trajetos[i]->y);
        }
    }
}