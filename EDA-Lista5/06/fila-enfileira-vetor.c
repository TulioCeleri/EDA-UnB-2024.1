#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

// void criar_fila(fila *f){
//     f->dados = malloc(sizeof(fila));
//     f->N = 2;
//     f->p = 0;
//     f->u = 0;
// }

int enfileira (fila *f, int x){
    if (f->u == f->N)
    {
        int *novo_dados = realloc(f->dados, 2 * f->N * sizeof(int));
        if (novo_dados == NULL)
        {
            return 0;
        }
        
        f->dados = novo_dados;
        f->N *= 2;
    }

    f->dados[f->u++] = x;
    
    return 1; 
}

// int main(){
//     fila *Fila = malloc(sizeof(fila));
//     criar_fila(Fila);
//     enfileira(Fila, 2);
//     enfileira(Fila, 3);
//     enfileira(Fila, 4);
//     enfileira(Fila, 7);
//     printf("%d\n", Fila->dados[0]);
//     printf("%d\n", Fila->dados[1]);
//     printf("%d\n", Fila->dados[2]);
//     free(Fila);
//     return 0;
// }