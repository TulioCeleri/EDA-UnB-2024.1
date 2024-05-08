#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;   
    struct celula *prox;
} celula;

// celula *criar_celula(int x);

int desempilha (celula *p, int *y){
    celula *aux = p->prox;
    if (aux == NULL)
    {
        return 0;
    }
    
    *y = p->prox->dado;
    p->prox = aux->prox;
    return 1;
}

// int empilha (celula *p, int x){

//     celula *nova_celula = criar_celula(x);
//     if (nova_celula == NULL)
//     {
//         return 0;
//     }
    
//     nova_celula->prox = p->prox;
//     p->prox = nova_celula;

//     return 1;
// }

// celula *criar_celula(int x){
//     celula *novo = malloc(sizeof(celula));
//     novo->dado = x;
//     novo->prox = NULL;
//     return novo;
// }

// int main(){
//     int y;
//     celula *cabeca = criar_celula(-1);
//     empilha(cabeca, 1);
//     empilha(cabeca, 2);
//     empilha(cabeca, 3);
//     empilha(cabeca, 89);
//     desempilha(cabeca, &y);
//     celula *teste = cabeca->prox;
//     printf("Elemento removido: %d\n", y);
//     while (teste)
//     {
//         printf("%d\n", teste->dado);
//         teste = teste->prox;
//     }

//     return 0;
// }
