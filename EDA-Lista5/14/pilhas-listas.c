#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void empilha (celula *p, int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = p->prox;
    p->prox = novo;
}

int desempilha (celula *p, int *y){
    if (p->prox == NULL)
    {
        return 0;
    }

    *y = p->prox->dado;
    p->prox = p->prox->prox;
    return 1;
}

celula *cria_pilha(int x){
    celula *nova_pilha = malloc(sizeof(celula));
    nova_pilha->dado = x;
    nova_pilha->prox = NULL;
    return nova_pilha;
}

int main(void){
    celula *pilha = cria_pilha(-1);
    int y;
    empilha(pilha, 1);
    empilha(pilha, 43);
    empilha(pilha, 22);
    desempilha(pilha, &y);
    printf("Elemento removido: %d\n", y);
    celula *aux = pilha->prox;
    while (aux)
    {
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }

    return 0;
}