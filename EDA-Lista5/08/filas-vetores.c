#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // Vetor que representa a fila
    int N; // Tamanho da fila
    int inicio, fim; // Indicadores de inicio e final da fila
} fila;

int enfileira (fila *f, int x){
    if ((f->fim + 1) % f->N == f->inicio)
    {
        return 0;
    }

    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    return 1;
}

int desenfileira (fila *f, int *y){
    if (f->inicio == f->fim)
    {
        return 0;
    }

    *y = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->N;
    
    return 1;
}

// void criar_fila(fila *f){
//     f->v = malloc(sizeof(fila));
//     f->N = 10;
//     f->inicio = 0;
//     f->fim = 0;
// }

// int main(){
//     fila *Fila = malloc(sizeof(fila));
//     int y;
//     criar_fila(Fila);
//     enfileira(Fila, 33);
//     enfileira(Fila, 14);
//     enfileira(Fila, 1);
//     enfileira(Fila, 23);
//     for (int i = Fila->inicio; i < Fila->fim; i++)
//     {
//         printf("%d\n", Fila->v[i]);
//     }
//     printf("\n");
//     desenfileira(Fila, &y);
//     printf("Y: %d\n", y);
//     for (int i = Fila->inicio; i < Fila->fim; i++)
//     {
//         printf("%d\n", Fila->v[i]);
//     }

//     return 0;
// }