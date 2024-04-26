#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2){
    celula *atual_l = l->prox;
    while (atual_l != NULL)
    {
        celula *nova_celula = malloc(sizeof(celula));
        nova_celula->dado = atual_l->dado;
        nova_celula->prox = NULL;
        if (atual_l->dado % 2 != 0)
        {
            l1->prox = nova_celula;
            l1 = l1->prox;
        }
        else
        {
            l2->prox = nova_celula;
            l2 = l2->prox;
        }
        atual_l = atual_l->prox;
    }
}