#include "grafoponderado.h"
#include <stdio.h>
#include <stdlib.h>

Lista *alocaLista(){

    Lista *plista = (Lista *)malloc(sizeof(Lista));
    if (plista != NULL) {
        plista ->pCabeca = NULL;
        plista ->pUltimo = NULL;
        printf("Lista criada\n");
    } else {
        printf("Falha ao alocar memória para a lista\n");
    }
    return plista;
}

int TLista_EhVazia(Lista *plista ) {
    return (plista->pCabeca == plista->pUltimo);
}

int insereLista(Lista *plista, Item x) {
    if (plista == NULL) {
        printf("Lista não inicializada\n");
        return 0; // Se a lista não foi inicializada, não é possível inserir um item
    }

    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
    if (novaCelula == NULL) {
        printf("Falha ao alocar memória para a célula\n");
        return 0; // Se a alocação falhar, retorna 0 indicando erro na inserção
    }

    novaCelula->pItem = x; // pensar em quais informações estão sendo passadas e de que forma
    novaCelula->prox = NULL;

    if (TLista_EhVazia(plista)) {
        plista->pCabeca->prox = novaCelula;
    } 
    else {
        plista->pUltimo->prox = novaCelula;
    }

    plista->pUltimo = novaCelula;
    printf("Inseriu\n");
    return 1;
}

// Função para liberar a memória da lista
void desalocaLista(Lista **plista ) {
    Celula *atual = (*plista )->pCabeca;
    while (atual != NULL) {
        Celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(*plista);
    plista  = NULL;
    printf("Lista desalocada\n");
}

//Remove Lista
//void removeLista(Lista* listaC, Item x );

//Função de alocação do labirinto com mensagem de erros em caso de erro    
Grafo* alocaGrafo(int n){
    
    Grafo* newgrafo = (Grafo*)malloc(sizeof(Grafo));
    newgrafo->plista = alocaLista();
    newgrafo->caminho = (int*)malloc(n+1 * sizeof(int));
    newgrafo->distancia = 0;
    newgrafo->ncity = 0;
    return newgrafo;
}

//Função de desaloção do labirinto
void desalocaGrafo(Grafo** pGrafo){
    desalocaLista((*pGrafo)->plista);
    (*pGrafo)->plista = NULL;
    free((*pGrafo)->caminho);
    for (int i = 0; i < (*pGrafo)->ncity; i++){
    
        free((*pGrafo)->mapa[i]);
    }
    free((*pGrafo)->mapa);
    free(*pGrafo);

}

//Leitura dos dados do labirinto
Grafo* leGrafo(Grafo* pGrafo){

    int n,i,j,k,m;
    i=0;
    scanf("%d",&n);

    pGrafo = alocaGrafo(n);
    pGrafo->ncity = n;
    
    return pGrafo;
}

//Função recursiva
int encontraCaminho(Grafo* pGrafo, int city,int aux,int achou){
    
    if(aux >= pGrafo->ncity){
        pGrafo->caminho[aux] = city;
        return 1;
    }else if(aux < pGrafo->ncity){

        pGrafo->caminho[aux] = city;
        city = verificamenor(pGrafo,city,&aux);
        achou = encontraCaminho(pGrafo,city,aux+1,achou);
    }
    
    return achou;
    
}

//Função verifica menor distancia 
int verificamenor(Grafo *pG,int cidade,int *n){
    int aux,proxcidade,j,inicio,aux1;
    aux1 = 0;
    aux = 9999999;
    inicio = pG->mapa[cidade][0];
    //tranca os lugares que ja passou
    for(int i = 0;i < *n+1;i++){
        j = pG->caminho[i];
        pG->mapa[cidade][j] = -1;
    }
    //procura a menor distancia
    for (int i = 0; i < pG->ncity; i++){
        if(pG->mapa[cidade][i] > -1){
            if(pG->mapa[cidade][i] < aux){
                aux = pG->mapa[cidade][i];
                proxcidade = i;
                aux1 = 1;
            }
        }
    }
    //caso final de retornar a cidade inicial
    if (aux1 == 0){
        aux = inicio;
        proxcidade = 0;
    }
    
    pG->distancia = pG->distancia + aux;
    return proxcidade;
}

//Impressão da saida de acordo com a opção de entrada
void imprimeCaminho(Grafo* pGrafo){
    
    for(int i = 0;i < pGrafo->ncity+1;i++){
        printf("%d ",pGrafo->caminho[i]);
    }
    printf("\n%d\n",pGrafo->distancia);

}

