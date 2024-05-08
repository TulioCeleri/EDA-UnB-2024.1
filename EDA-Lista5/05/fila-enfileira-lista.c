#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void *enfileira (celula *f, int x){
    celula *novo = malloc(sizeof(celula));
    if (novo)
    {
        novo->dado = x;
        novo->prox = NULL;
        if (f->prox == NULL)
        {
            f->prox = novo;
            return novo;
        }
        else
        {
            celula *aux = f;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
            return f;
        }
    }
    else
    {
        return NULL;
    }   
}

// int main() {
//     // Criando a cabeça da fila
//     celula *fila = malloc(sizeof(celula));
//     fila->prox = NULL;

    
//     // Enfileirando alguns elementos
//     enfileira(fila, 10);
//     enfileira(fila, 20);
//     enfileira(fila, 30);

//     // Imprimindo os elementos enfileirados
//     printf("Elementos na fila:\n");
//     celula *atual = fila->prox;
//     while (atual != NULL) {
//         printf("%d\n", atual->dado);
//         atual = atual->prox;
//     }

//     return 0;
// }

