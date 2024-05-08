#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v; // Vetor que contem os elementos da pilha
    int N; // Tamanho de v
    int topo; // Indicador do topo
} pilha;

void empilha (pilha *p, int x){
    if (p->topo == p->N)
    {
        int *novo_dado = realloc(p->v, p->N * 2 * sizeof(int));
        p->v = novo_dado;
        p->N *= 2;
    }
    
    p->v[p->topo++] = x;
}

int desempilha (pilha *p, int *y){
    if (p->topo == 0)
    {
        return 0;
    }

    p->topo--;
    *y = p->v[p->topo];
    return 1;
}

// pilha *cria_pilha(){
//     pilha *nova_pilha = malloc(sizeof(pilha));
//     nova_pilha->N = 10;
//     nova_pilha->topo = 0;
//     nova_pilha->v = malloc(nova_pilha->N * sizeof(int));
//     return nova_pilha;
// }

// int main(void){
//     pilha *pi = cria_pilha();
//     int y;
//     empilha(pi, 2);
//     empilha(pi, 54);
//     empilha(pi, 21);
//     desempilha(pi, &y);
//     printf("Removido: %d\n", y);
//     desempilha(pi, &y);
//     printf("Removido: %d\n", y);
//     pilha *aux = pi;
//     for (int i = aux->topo - 1; i >= 0; i--)
//     {
//         printf("%d\n", aux->v[i]);
//     }
//     return 0;
// }