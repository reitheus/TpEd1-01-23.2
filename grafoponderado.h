#ifndef GRAFOPONDERADO_H
#define GRAFOPONDERADO_H

typedef struct grafo{
    int **mapa;// Matriz com as distancias
    int *caminho;// vetor do caminho
    int ncity; // numeros de cidade
    int distancia;// distanica do caminho

}Grafo;

//Função de alocação do grafo
Grafo* alocaGrafo(int );

//Função de desalocação do grafo
void desalocaGrafo(Grafo** );

//Função de entrada de dados
Grafo* leGrafo(Grafo* );

//Função de encontra caminho
int encontraCaminho(Grafo* ,int ,int );

//Imprime caminho
void imprimeCaminho(Grafo* );

#endif //TAD Grafo Ponderado
