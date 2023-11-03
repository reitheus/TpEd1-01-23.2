#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

//funções da biblioteca 

// Definindo a estrutura do grafo
struct grafo {
    int **city;
    int distancia;
    int *ordemCidades;
};

// Função para alocar memória para o grafo
Grafo **alocarGrafo(int n) {
    Grafo **cidades = (Grafo **)malloc(n * sizeof(Grafo *));

    for (int i = 0; i < n; i++) {
        cidades[i] = (Grafo *)malloc(n * sizeof(Grafo));
    }

    return cidades;
}

// Função para liberar memória alocada para o grafo
Grafo **desalocarGrafo(Grafo **cidades, int n) {
    for (int i = 0; i < n; i++) {
        free(cidades[i]);
    }
    free(cidades);

    return NULL;
}

// Função para ler os dados de entrada fornecidos pelo usuário
Grafo **leGrafo(Grafo **cidades, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", cidades[i]->city[j]);
        }
    }

    return cidades;
}

// Função recursiva para encontrar o menor caminho
Grafo *encontraCaminho(Grafo **cidades, int n, int menorvalor, int aux, int n2, Grafo *d, Grafo *trajeto) {
    if (n == -1) {
        return d;
    }

    if (aux == n) {
        return encontraCaminho(cidades, n, menorvalor, aux - 1, n2, d, trajeto);
    }

    if (aux < n) {
        if (menorvalor > *cidades[n]->city[aux]) {
            menorvalor = *cidades[n]->city[aux];
        }
        return encontraCaminho(cidades, n, menorvalor, aux - 1, n2, d, trajeto);
    }

    if (aux == 0) {
        if (menorvalor > *cidades[n]->city[aux]) {
            menorvalor = *cidades[n]->city[aux];
        }
        d->distancia += menorvalor;
        aux = n2;
        menorvalor = 50000;
        return encontraCaminho(cidades, n - 1, menorvalor, aux, n2, d, trajeto);
    }

    return d;
}

// Função para imprimir o menor caminho e a distância percorrida
void imprimeCaminho(int n, Grafo *d, Grafo *trajeto) {
    for (int i = 0; i < n; i++) {
        printf("%d ", trajeto->ordemCidades[i]);
    }

    printf("\n%d", d->distancia);
}
