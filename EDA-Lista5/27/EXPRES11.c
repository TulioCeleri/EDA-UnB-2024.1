#include <stdio.h>
#include <stdlib.h>
#define MAX 100001

typedef struct pilha{
    char *dados;
    int tamanho;
    int topo;
} pilha;

pilha *cria_pilha(int tam){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    p->dados = (char*)malloc(sizeof(char) * tam);
    p->tamanho = tam;
    p->topo = -1;
    return p;
}

int empilhar(pilha *p, char c){
    if (p->topo == p->tamanho)
    {
        return 0;
    }
    
    p->dados[++p->topo] = c;
    return 1;
}

char desempilhar(pilha *p){
    return p->dados[p->topo--];
}

int pilha_vazia(pilha *p){
    return p->topo == -1;
}

char BemDefinida(char *cadeia){
    pilha *p = cria_pilha(MAX);
    int cont = 0;
    while (cadeia[cont] != '\0')
    {
        if (cadeia[cont] == '(' || cadeia[cont] == '[' || cadeia[cont] == '{')
        {
            empilhar(p, cadeia[cont]);
        }
        else
        {
            if (pilha_vazia(p))
            {
                free(p->dados);
                free(p);
                return 'N';
            }
            char topo = desempilhar(p);
            if ((cadeia[cont] == ')' && topo != '(') ||
                (cadeia[cont] == ']' && topo != '[') ||
                (cadeia[cont] == '}' && topo != '{') ){
                
                free(p->dados);
                free(p);
                return 'N';
            } 
        }
        cont++;
    }
    
    if (!pilha_vazia(p))
    {
        free(p->dados);
        free(p);
        return 'N';
    }
    free(p->dados);
    free(p);
    return 'S';
}

int main(void){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        char cadeia[MAX];
        scanf("%s", cadeia);
        char resp = BemDefinida(cadeia);
        printf("%c\n", resp);
    }
    return 0;
}