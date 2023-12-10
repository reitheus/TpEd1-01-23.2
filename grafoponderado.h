#ifndef GRAFOPONDERADO_H
#define GRAFOPONDERADO_H

#include "lista.h"
#include <stdbool.h>

typedef struct grafo{
    int *caminho;// vetor do caminho
    int ncity; // numeros de cidade
    int distancia;// distanica do caminho
    Lista *plista;
    Lista *pLFinal;
}Grafo;

//Função de alocação do grafo
Grafo* alocaGrafo(int );

//Função de desalocação do grafo
void desalocaGrafo(Grafo** );

//Função de entrada de dados
Grafo* leGrafo(Grafo* );

//Função de achar o menor
int verificamenor(Grafo* ,int ,int* );

//Função de encontra caminho
int encontraCaminho(Grafo* ,int ,int ,int );

//Imprime caminho
void imprimeCaminho(Grafo* );

#endif //TAD Grafo Ponderado
