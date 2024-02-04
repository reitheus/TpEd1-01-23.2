#include "arvore.h"

void alocaArvore(No **arvore) {
    *arvore = NULL;
    
}

void liberaArvore(No **ppRaiz){
    if((*ppRaiz) != NULL){
        liberaArvore(&(*ppRaiz)->esq);
        liberaArvore(&(*ppRaiz)->dir);
        free(*ppRaiz);
        *ppRaiz = NULL;
    }
}

No* noCria(Chave *dado){
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->item = *dado;
    novoNo->pai = NULL;
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    novoNo->cor = RED;
    return novoNo;
}

void le(No** ppRaiz, int n) {
    Chave x; 
    for (int i = 0; i < n; i++) {
        scanf("%s",x.nome);
        scanf("%d",&x.idade);
        insere(ppRaiz, x); // Chama a função de inserção para inserir o nó na árvore
    }
}

No* rotacaoEsquerda (No *ppRaiz,No *x){
    No* pAux = x->dir;
    x->dir = pAux->esq;
    if(pAux->esq != NULL){
        pAux->esq->pai = x;
    }
    pAux->pai = x->pai;
    if(x->pai == NULL){
        ppRaiz = pAux;
    }else if(x == x->pai->esq){
        x->pai->esq = pAux;
    }else{
        x->pai->dir = pAux;
    }
    pAux->esq = x;
    x->pai = pAux;
    return ppRaiz;
}

No* rotacaoDireita(No *ppRaiz,No *y){
    No* pAux = y->esq;
    y->esq = pAux->dir;
    if(pAux->dir != NULL){
        pAux->dir->pai = y;
    }
    pAux->pai = y->pai;
    if(y->pai == NULL){
        ppRaiz = pAux;
    }else if(pAux == pAux->pai->esq){
        pAux->pai->esq = pAux;
    }else{
        pAux->pai->dir = pAux;
    }
    pAux->esq = y;
    y->pai = pAux;
    return ppRaiz;
}

No* balanceamento(No* ppRaiz,No* novoN){
    No* y = NULL;
    while(novoN->pai != NULL && novoN->pai->cor == RED){
        if(novoN->pai == novoN->pai->pai->esq){
            y = novoN->pai->pai->dir;
            if(y->cor == RED){
                //caso 1: cor do pai do pai da direita do novo no é vermelho
                novoN->pai->cor = BLACK;
                y->cor = BLACK;
                novoN->pai->pai->cor = RED;
                novoN = novoN->pai->pai;
            }else{
                if(novoN == novoN->pai->dir){
                    //caso 2: novo no é igual ao pai da direita
                    novoN = novoN->pai;
                    ppRaiz = rotacaoEsquerda(ppRaiz,novoN);
                }
                //caso 3: a cor do pai do novo no é preta
                novoN->pai->cor = BLACK;
                novoN->pai->pai->cor = RED;
                ppRaiz = rotacaoDireita(ppRaiz,novoN->pai->pai);
            }
        }else{
            y = novoN->pai->pai->esq;
            if(y != NULL && y->cor == RED){
                //caso 1: cor do pai do pai da direita do novo no é vermelho
                novoN->pai->cor = BLACK;
                y->cor = BLACK;
                novoN->pai->pai->cor = RED;
                novoN = novoN->pai->pai;
            }else{
                if(novoN == novoN->pai->dir){
                    //caso 2: novo no é igual ao pai da direita
                    novoN = novoN->pai;
                    ppRaiz = rotacaoDireita(ppRaiz,novoN);
                }
                //caso 3: a cor do pai do novo no é preta
                novoN->pai->cor = BLACK;
                novoN->pai->pai->cor = RED;
                ppRaiz = rotacaoEsquerda(ppRaiz,novoN->pai->pai);
            }
        }
    }
    if(ppRaiz != NULL){
        ppRaiz->cor = BLACK;
    }
    return ppRaiz;
}

void insere(No **ppRaiz,Chave dado){
    No *newNo = noCria(&dado);
    No *x = *ppRaiz;
    No *y = NULL;
    while (x != NULL)
    {
        y = x;
        if(dado.idade < x->item.idade){
            x = x->esq;
        }else{
            x = x->dir;
        }
    }
    
    newNo->pai = y;
    if(y == NULL){
        (*ppRaiz) = newNo;
    }else if(dado.idade < y->item.idade){
        y->esq = newNo;
    }else if(dado.idade > y->item.idade){
        y->dir = newNo;
    }else{
        if(strcmp(dado.nome,y->item.nome) < 0){
            y->esq = newNo;
        }else{
            y->dir = newNo;
        }
    }
    newNo->cor = RED;
    *ppRaiz = balanceamento(*ppRaiz,newNo);
}

void printInOrden(No *pRaiz){
    //No *aux = pRaiz;
    if(pRaiz == NULL){
        return;
    }else{
        printInOrden(pRaiz->esq);
        printf("Nome: %s\n",pRaiz->item.nome);
        printf("Idade: %d\n",pRaiz->item.idade);
        printInOrden(pRaiz->dir);
    }
}


