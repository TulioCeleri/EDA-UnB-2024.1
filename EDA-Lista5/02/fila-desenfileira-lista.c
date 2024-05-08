#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int desenfileira (celula *f, int *y){
    if (f == NULL || f->prox == NULL)
    {
        return 0;
    }
    
    *y = f->prox->dado;
    f->prox = f->prox->prox;
    return 1;
}
