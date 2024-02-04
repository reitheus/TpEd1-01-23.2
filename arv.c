#include "arvore.h"


bool alocarArvore(No** arvore) {
    *arvore = (No*)malloc(sizeof(No));
    if (*arvore == NULL) {
        printf("Erro ao alocar memória para a árvore.\n");
        return false;
    }
    else 
        return true;
}

No* criaNo(No* arv, Chave x) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return NULL; 
    }
    
    novoNo->item = x;
    novoNo->cor = BLACK; // inicializar com vermelho
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    if (*arv == NULL) {
        // Se a árvore estiver vazia, o novo nó será a raiz
        *arv = novoNo;
    } else {
        // Caso contrário, insere o novo nó na árvore
        No* temp = *arv; // Ponteiro temporário para percorrer a árvore

        while (true) {
            // Comparação por idade
            if (x.idade < temp->dados.idade) {
                if (temp->pEsq == NULL) {
                    temp->pEsq = novoNo; // Inserir à esquerda
                    break;
                } else {
                    temp = temp->pEsq; // Continuar percorrendo à esquerda
                }
            } else if (x.idade > temp->dados.idade) {
                if (temp->pDir == NULL) {
                    temp->pDir = novoNo; // Inserir à direita
                    break;
                } else {
                    temp = temp->pDir; // Continuar percorrendo à direita
                }
            } else { // Idades iguais, comparar alfabeticamente os nomes
                int cmp = strcmp(x.nome, temp->dados.nome);
                if (cmp < 0) {
                    if (temp->pEsq == NULL) {
                        temp->pEsq = novoNo; // Inserir à esquerda
                        break;
                    } else {
                        temp = temp->pEsq; // Continuar percorrendo à esquerda
                    }
                } else {
                    if (temp->pDir == NULL) {
                        temp->pDir = novoNo; // Inserir à direita
                        break;
                    } else {
                        temp = temp->pDir; // Continuar percorrendo à direita
                    }
                }
            }
        }
        // Após a inserção, chama a função de balanceamento e controle de cor
        balanceamento(arv, novoNo);
    }

    return novoNo;
}

// função para manter a cores invertidas entre os nós 
struct trocaCor(struct No* n){
    n->cor = !n->cor;
    if(n->pEsq != NULL)//se exixtir um nó a esquerda, inverte a cor 
        n->pEsq->cor = !n->pEsq->cor;
    if(n->pDir != NULL)// se existir um nó a direita, inverte a cor 
        n->pDir->cor = !n->pDir->cor; 
}


/*/
void insere(No **ppRaiz,Chave dado){
    No *pAux = noCria(dado);
    No *x = *ppRaiz;
    No *y = NULL;
    
    while(x != NULL){
        y = x;
        if(pAux->item.idade < x->item.idade){
            x = x->esq;
        }else{
            x = x->dir;
        }
    }

    pAux->pai = y;
    if(y == NULL){
        *ppRaiz = pAux;
    }else {
        if(pAux->item.idade < y->item.idade){

            y->esq = pAux;

        }else if(pAux->item.idade > y->item.idade){
            y->dir = pAux;

        }
    }
    balanceamentoRecursivo(ppRaiz,pAux);

}*/

void balanceamento(No** ppRaiz,No* novoN){
    
    while(novoN != *ppRaiz && novoN->pai->cor == RED){
        if(novoN->pai == novoN->pai->pai->esq){
            No* y = novoN->pai->pai->dir;
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
                    rotacaoEsquerda(ppRaiz,novoN);
                }
                //caso 3: a cor do pai do novo no é preta
                novoN->pai->cor = BLACK;
                novoN->pai->pai->cor = RED;
                rotacaoDireita(ppRaiz,novoN->pai->pai);
            }
        }else{
            No* y = novoN->pai->pai->esq;
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
                    rotacaoDireita(ppRaiz,novoN);
                }
                //caso 3: a cor do pai do novo no é preta
                novoN->pai->cor = BLACK;
                novoN->pai->pai->cor = RED;
                rotacaoEsquerda(ppRaiz,novoN->pai->pai);
            }
        }
    }
    (*ppRaiz)->cor = BLACK;
}

void le(No* arvore, int n) {
    Chave x; 
    for (int i = 0; i < n; i++) {
        scanf("%s %d", x.nome, &x.idade);
        insere(*arvore, x); // Chama a função de inserção para inserir o nó na árvore
    }
}


struct rotacaoDireita(No* n){//rotaçao da arvore para direita 
    No* aux = n->pEsq;
    n->pEsq = aux->pDir; 
    aux->pDir = n;
    aux->cor = n->cor;
    n->cor = RED;
    return aux; 
}

struct rotacaoEsquerda(No* n){//rotaçao da arvore para a esquerda 
    No* aux = n->pDir;
    n->pDir = aux->pEsq; 
    aux->esq = n;
    aux->cor = n->cor;
    n->cor = RED;
    return aux; 
}

//função para corrigir seguencia de nós vermelhos 
struct No* moveEsq(No* n){
    trocaCor(n);
    if(cor(n->pDir->pEsq) == RED){
        n->pDir = rotacaoDireita(n->pDir);
        n = rotacaoEsquerda(n);
        trocaCor(n);
    }
    return n; 
}

struct No* moveDir(No* n){
    trocaCor(n);
    if(cor(n->pEsq->pEsq) == RED){
        n = rotacaoDireita(n);
        trocaCor(n);
    }
    return n; 
}

struct balenceamento(No* n){//realiza o balanceamento da arvore 
    if(cor(n->pDir) == RED)
        n = rotacaoEsquerda(n);
    if(n->pEsq != NULL && cor(n->pDir) == RED && cor(n->pEsq->Esq) == RED)
        n = rotacaoDireita(n);
    if(cor(n->pEsq) == RED && COR(n->dir) == RED)
        trocaCor(n);
    return n;     
}

void desalocarArvore(No* arvore) {
    if (*arvore == NULL) {
        return;
    }

    desalocarNos(&(*arvore));
    free(*arvore);
    *arvore = NULL;
}

void desalocarNos(No** no) {
    if (*no == NULL) {
        return;
    }

    desalocarNos(&((*no)->pEsq));
    desalocarNos(&((*no)->pDir));
    free(*no);
    *no = NULL;
}

bool *removeNo(No** ppRaiz, Chave *px){// px item para remover

    if(*ppRaiz == NULL)// arvore vazia 
        return false; 
    
    int existe = consultaSeExiste(ppRaiz, px);   
    if(existe == 0)
        return false;

    No* aux = ppRaiz; 
    else {// codições do nó 
        if()

        
    }

    balanceamento(ppRaiz); 

}

bool consultaSeExiste(No* pRaiz, Chave px) {
    No* aux = pRaiz;
    while (aux != NULL) {
        int cmp = strcmp(px.nome, aux->item.nome);
        if (cmp == 0) {
            if (px.idade == aux->item.idade) {
                return true;
            }
        } else if (cmp > 0) {
            aux = aux->dir;
        } else {
            aux = aux->esq;
        }
    }
    return false;
}



bool removeNo(No** ppRaiz, Chave* px) {
    if (*ppRaiz == NULL) {
        return false; // Árvore vazia
    }

    // Verifica se o item a ser removido existe na árvore
    No* pai = NULL;
    No* atual = *ppRaiz;
    while (atual != NULL) {
        int cmp = strcmp(px->nome, atual->item.nome);
        if (cmp == 0) {
            if (px->idade == atual->item.idade) {
                // Item encontrado, realiza a remoção
                if (atual->esq == NULL && atual->dir == NULL) {
                    // Caso 1: Nó folha
                    if (pai == NULL) {
                        *ppRaiz = NULL;
                    } else if (pai->esq == atual) {
                        pai->esq = NULL;
                    } else {
                        pai->dir = NULL;
                    }
                    free(atual);
                } else if (atual->esq == NULL || atual->dir == NULL) {
                    // Caso 2: Nó com um filho
                    No* filho = (atual->esq != NULL) ? atual->esq : atual->dir;
                    if (pai == NULL) {
                        *ppRaiz = filho;
                    } else if (pai->esq == atual) {
                        pai->esq = filho;
                    } else {
                        pai->dir = filho;
                    }
                    free(atual);
                } else {
                    // Caso 3: Nó com dois filhos
                    No* sucessor = atual->dir;
                    while (sucessor->esq != NULL) {
                        sucessor = sucessor->esq;
                    }
                    atual->item = sucessor->item;
                    removeNo(&(atual->dir), &(sucessor->item));
                }
                balanceamento(ppRaiz); // Chama a função de balanceamento após a remoção
                return true;
            }
        } else if (cmp > 0) {
            pai = atual;
            atual = atual->dir;
        } else {
            pai = atual;
            atual = atual->esq;
        }
    }
    return false; // Item não encontrado
}

