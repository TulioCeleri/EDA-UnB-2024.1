#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void enfileira (celula **f, int x){
    celula *aux = *f;
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    if (*f == NULL)
    {
        *f = novo;
        novo->prox = novo;
    }

    else
    {
        while (aux->prox != (*f))
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = (*f);
    }
}

int desenfileira (celula *f, int *y){
    if (f->prox == f)
    {
        return 0;
    }
    celula *aux = f->prox;
    *y = aux->dado;
    f->prox = aux->prox;
    free(aux);
    
    return 1;
}

// int main(void){
//     celula *fila = NULL;
//     int y;
//     enfileira(&fila, 3);
//     enfileira(&fila, 4);
//     enfileira(&fila, 5);
//     enfileira(&fila, 6);
//     desenfileira(fila, &y);
//     printf("Elemento removido: %d\n", y);
//     celula *teste = fila;

//     do
//     {
//         printf("%d\n", teste->dado);
//         teste = teste->prox;
//     } while (teste->dado != fila->dado);
    
//     return 0;
// }