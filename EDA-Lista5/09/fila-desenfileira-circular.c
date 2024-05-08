#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira (fila *f, int *y){
    if (f->p == f->u)
    {
        int *novo_dados = realloc(f->dados, 2 * f->N * sizeof(int));
        if (novo_dados == NULL)
        {
            return 0;
        }
        
        f->dados = novo_dados;
        f->N *= 2;
    }

    *y = f->dados[f->p];
    f->p = (f->p + 1) % f->N;
    
    return 1;
}