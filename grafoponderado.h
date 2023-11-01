#ifndef GRAFOPONDERADO_H
#define GRAFOPONDERADO_H

typedef struct grafo{
    int **mapa;
    int *caminho;
    int ncity;
}Grafo;

//Função de alocação do grafo
Grafo *alocaGrafo(int );

//Função de desalocação do grafo
void desalocaGrafo(Grafo** );

//Função de entrada de dados
Grafo* leGrafo(Grafo* );

//Função de encontra caminho
int encontraCaminho(Grafo* ,int );

//Imprime caminho
Grafo* imprimeCaminho(Grafo* );

#endif //TAD Grafo Ponderado
