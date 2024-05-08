#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int desenfileira(fila *f, int *y) {
    if (f == NULL || f->p == f->u) {
        // Verifica se a fila está vazia
        return 0;
    } else {
        *y = f->dados[f->p]; // Salva o elemento a ser removido em y
        f->p = f->p + 1; // Atualiza o índice do início da fila
        return 1; // Retorna 1 indicando sucesso na remoção
    }
}