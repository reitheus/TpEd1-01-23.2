#ifndef GRAFOPONDERADO_H
#define GRAFOPONDERADO_H

typedef struct grafo{
    int *caminho;// vetor do caminho
    int ncity; // numeros de cidade
    int distancia;// distanica do caminho
    Lista *plista;
}Grafo;

typedef struct item{
    int distancia;
    int cityatual;
}Item;

typedef struct celula{
    Item *pItem;
    Celula *prox;
}Celula;

typedef struct lista{
    struct Celula *pCabeca;
    struct Celula *pUltimo;
}Lista;

//Função de alocação do grafo
Grafo* alocaGrafo(int );

//Aloca lista
Lista *alocaLista();

//Desalocacão de lista
void desalocaLista(Lista** );

//Inicia lista
void insereLista(Lista* ,Item );

//Remove Lista
void removeLista(Lista* ,Item );

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

//Função de ordenação 
void ordenaLista(Lista* );

//Função imprimi ordenação 
void imprimeOrdenado(Lista* );

#endif //TAD Grafo Ponderado
