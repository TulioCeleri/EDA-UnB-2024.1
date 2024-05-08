#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    if (f->p == f->u) {
        // A fila está vazia, não é possível desenfileirar
        return 0;
    }
    
    // Remova o elemento da fila e salve-o em y
    *y = f->dados[f->p];
    
    // Atualize o ponteiro p para apontar para o próximo elemento na fila
    f->p = (f->p + 1) % f->N;
    
    return 1; // Remoção bem sucedida
}