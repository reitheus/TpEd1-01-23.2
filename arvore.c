void rotacaoEsquerda (No **ppRaiz,No *x){
    No* pAux = x->dir;
    x->dir = pAux->esq;
    if(pAux->esq != NULL){
        pAux->esq->pai = x;
    }
    pAux->pai = x->pai;
    if(x->pai == NULL){
        *ppRaiz = pAux;
    }else if(x == x->pai->esq){
        x->pai->esq = pAux;
    }else{
        x->pai->dir = pAux;
    }
    pAux->esq = x;
    x->pai = pAux;
}

void rotacaoDireita(No **ppRaiz,No *y){
    No* pAux = y->esq;
    y->esq = pAux->dir;
    if(pAux->dir != NULL){
        pAux->dir->pai = y;
    }
    pAux->pai = y->pai;
    if(x->pai == NULL){
        *ppRaiz = pAux;
    }else if(pAux == pAux->pai->esq){
        pAux->pai->esq = pAux;
    }else{
        pAux->pai->dir = pAux;
    }
    pAux->esq = y;
    y->pai = pAux;
}