#include "arvore.h"


void alocaArvore(No **arvore) {
    //Função de Alocação
    *arvore = NULL;
    
}

void liberaArvore(No **ppRaiz){
    //Função de desalocação
    if((*ppRaiz) != NULL){
        liberaArvore(&(*ppRaiz)->esq);
        liberaArvore(&(*ppRaiz)->dir);
        free(*ppRaiz);
        *ppRaiz = NULL;
    }
}

No* noCria(Chave dado){
    //Função de criação de novo no
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->item = dado;
    novoNo->pai = NULL;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    novoNo->cor = RED;
    return novoNo;
}

void le(No** ppRaiz, int n) {
    //Função de leitura dos dados para inserção
    Chave x; 
    for (int i = 0; i < n; i++) {
        scanf("%s",x.nome);
        scanf("%d",&x.idade);
        insere(ppRaiz, x); // Chama a função de inserção para inserir o nó na árvore
    }
}

void rotacaoDireita(No **ppRaiz){
    //Função de rotação para a direita
    No *x, *y;
    y = *ppRaiz;                    //variavel auxiliar
    x = y->esq;                     //variavel auxiliar
    y->esq = x->dir;                //no esquerdo da raiz recebe o no filho da direita do no a esquerda da raiz
    x->dir = y;                     //no filho da direita do no a esquerda da raiz recebe a raiz
    x->cor = y->cor;                //no da esquerda da raiz recebe a cor da raiz
    y->cor = RED;                   //muda a cor da raiz para vermelho
    *ppRaiz = x;                    //ponteiro da raiz recebe o no que foi rodado
}

void rotacaoEsquerda(No **ppRaiz){
    //função de rotação da esquerda analogo a rotação da direita
    No *x, *y;
    y = *ppRaiz;
    x = y->dir;
    y->dir = x->esq;
    x->esq = y;
    x->cor = y->cor;
    y->cor = RED;
    *ppRaiz = x;
}

int eh_vermelho(No* pNo){
    //função de verificação da cor do no
    if(pNo == NULL)
        return 0;
    
    return pNo->cor == RED ? 1 : 0;
}

void balanceamento(No **ppRaiz,Chave dado){
    //função de inserçao e balanceamento
    if((*ppRaiz) == NULL){                                                  //verifica se o no atual é nulo e pode ser inserido
        *ppRaiz = noCria(dado);
        return;
    }

    if(dado.idade < (*ppRaiz)->item.idade){                                 //verifica para qual lado ir da árvore
        (*ppRaiz)->pai = (*ppRaiz)->esq;
        balanceamento(&(*ppRaiz)->esq,dado);
    }
    if(dado.idade > (*ppRaiz)->item.idade){
        (*ppRaiz)->pai = (*ppRaiz)->dir;
        balanceamento(&(*ppRaiz)->dir,dado);
    }

    //verificação das propiedades
    if(eh_vermelho((*ppRaiz)->dir) && !eh_vermelho((*ppRaiz)->esq)){        //caso 1: no da direita é vermelho e o no da esquerda não é
        rotacaoEsquerda(ppRaiz);
    }
    if(eh_vermelho((*ppRaiz)->esq) && eh_vermelho((*ppRaiz)->esq->esq)){    //caso 2:os dois nos a esquerda sao vermelhos
        rotacaoDireita(ppRaiz);
    }
    if(eh_vermelho((*ppRaiz)->esq) && eh_vermelho((*ppRaiz)->dir)){         //caso 3: ambos os nos são vermelhos
        inverteCor(*ppRaiz);
    }
}

void insere(No **ppRaiz,Chave dado){
    //Função de inserção
    balanceamento(ppRaiz,dado);                 //chamada da recusividade
    (*ppRaiz)->cor = BLACK;                     //garantia da raiz sempre ser preta;
}

void inverteCor(No *pNo){
    //Função de troca de cor
    pNo->cor = RED;
    pNo->dir->cor = BLACK;
    pNo->esq->cor = BLACK;
}

void printInOrden(No *pRaiz){
    //Função de imprenssão dos dados da arvore em ordem crescente
    if(pRaiz == NULL){
        return;
    }else{
        printInOrden(pRaiz->esq);
        printf("Nome: %s\n",pRaiz->item.nome);
        printf("Idade: %d\n",pRaiz->item.idade);
        printInOrden(pRaiz->dir);
    }
}
