#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    char *dados;
    int tamanho;
    int topo;
    int cont;
}pilha;

void inicializa_pilha(pilha *p, int tam){
    p->dados = malloc(tam * sizeof(char));
    p->tamanho = tam;
    p->topo = 0;
    p->cont = 0;
}

int empilha(pilha *p ,char c){
    if (p->topo == p->tamanho)
    {
        return 0;
    }
    p->dados[p->topo++] = c;
    p->cont++;
    return 1;
}

int main(void){
    int n;
    char letra;
    scanf("%d", &n);
    pilha p;
    inicializa_pilha(&p, n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            getchar();
        }
        scanf("%c", &letra);
        empilha(&p, letra);
    }

    int aux = 0;
    int resp = 0;
    int i = n - 1;
    while (i >= 0)
    {
        if (p.dados[i] == p.dados[aux])
        {
            resp++;
        }
        aux++;
        i--;
    }
    
    if (resp == n)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}