#include <stdio.h>
#include <stdlib.h>

// Definição de um nó da árvore
typedef struct no {
    int dado;
    struct no* esq;
    struct no* dir;
} no;

// Pilha para armazenar os nós da árvore
typedef struct pilha {
    struct no* node;
    struct pilha* next;
} pilha;

// Função para criar um novo nó da árvore
no * criar_no(int dado) {
    no* novo = malloc(sizeof(no));
    novo->dado = dado;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para empilhar um nó na pilha
void empilha(pilha** top, no* node) {
    pilha* novo = malloc(sizeof(pilha));
    novo->node = node;
    novo->next = *top;
    *top = novo;
}

// Função para desempilhar um nó da pilha
no* desempilha(pilha** top) {
    if (*top == NULL) {
        return NULL;
    }
    no* desempilhapedNode = (*top)->node;
    pilha* temp = *top;
    *top = (*top)->next;
    free(temp);
    return desempilhapedNode;
}

// Função para imprimir a árvore binária em pré-ordem de forma iterativa
void pre_ordem(no* raiz) {
    if (raiz == NULL) {
        return;
    }

    pilha* stack = NULL;
    empilha(&stack, raiz);

    while (stack != NULL) {
        no* currNode = desempilha(&stack);
        printf("%d ", currNode->dado);

        if (currNode->dir) {
            empilha(&stack, currNode->dir);
        }
        if (currNode->esq) {
            empilha(&stack, currNode->esq);
        }
    }
}

int main() {
    // Exemplo de árvore binária
    no* raiz = criar_no(1);
    raiz->esq = criar_no(2);
    raiz->dir = criar_no(3);
    raiz->esq->esq = criar_no(4);
    raiz->esq->dir = criar_no(5);

    printf("Árvore binária em pré-ordem: ");
    pre_ordem(raiz);
    printf("\n");


    return 0;
}
