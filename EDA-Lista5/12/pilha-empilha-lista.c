#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *cria_celula(int x); 

int empilha (celula *p, int x){

    celula *nova_celula = cria_celula(x);
    if (nova_celula == NULL)
    {
        return 0;
    }
    
    nova_celula->prox = p->prox;
    p->prox = nova_celula;

    return 1;
}

celula *cria_celula(int x){
    celula *novo = malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = NULL;
    return novo;
}

// int main(){
//     celula *cabeca = cria_celula(-1);

//     empilha(cabeca, 1);
//     empilha(cabeca, 2);
//     empilha(cabeca, 3);

//     celula *aux = cabeca->prox;
//     while (aux)
//     {
//         printf("%d\n", aux->dado);
//         aux = aux->prox;
//     }

//     free(cabeca);
    
//     return 0;
// }