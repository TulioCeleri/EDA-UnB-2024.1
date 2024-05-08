#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

int empilha (pilha *p, int x){
    if (p->topo == p->N)
    {
        int *novo_dados = realloc(p->dados, 2 * p->N * sizeof(int));
        if (novo_dados == NULL)
        {
            return 0;
        }

        p->dados = novo_dados;
        p->N *= 2;
    }

    p->dados[p->topo++] = x;

    return 1;
}
