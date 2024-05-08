#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;
    int N, p, u;
} fila;

int enfileira (fila *f, int x){
    if ((f->u+1) % f->N == f->p)
    {
        int *novo_dados = realloc(f->dados, f->N * 2 * sizeof(int));
        if (novo_dados == NULL)
        {
            return 0;
        }
        
        f->dados = novo_dados;
        f->N *= 2;
    }

    
    f->dados[f->u] = x;
    f->u = (f->u + 1) % f->N;
    return 1;
}

fila *cria_fila(){
    fila *novo = malloc(sizeof(fila));
    novo->N = 5;
    novo->p = 0;
    novo->u = 0;
    novo->dados = malloc(novo->N * sizeof(int));
    return novo;
}

int main(){
    fila *Fila = cria_fila();
    enfileira(Fila, 3);
    enfileira(Fila, 4);
    enfileira(Fila, 5);
    enfileira(Fila, 6);
    enfileira(Fila, 7);
    enfileira(Fila, 8);
    fila *teste = Fila;
    printf("%d\n", teste->u);
    // int i = teste->p; // Comece do índice de início
    // while (i != teste->u) // Enquanto não alcançar o índice de fim
    // {
    //     printf("%d\n", teste->dados[i]);
    //     i = (i + 1) % teste->N; // Avance para o próximo elemento
    // }
    

    

    return 0;
}