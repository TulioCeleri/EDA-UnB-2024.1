#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita,*esquerda;
} no;

void inserir(no **r, int x){
    if (*r == NULL)
    {
        *r = malloc(sizeof(no));
        (*r)->valor = x;
        (*r)->direita = NULL;
        (*r)->esquerda = NULL;
    }
    else
    {
        if (x < (*r)->valor)
        {
            inserir(&((*r)->esquerda), x);
        }
        else
        {
            inserir(&((*r)->direita), x);
        }
    } 
}

void imprimir_preordem(no *r){
    if (r != NULL)
    {
        printf("%d ", r->valor);
        imprimir_preordem(r->esquerda);
        imprimir_preordem(r->direita);
    }
}

void imprimir_emordem(no *r){
    if (r != NULL)
    {
        imprimir_emordem(r->esquerda);
        printf("%d ", r->valor);
        imprimir_emordem(r->direita);
    }
}
void imprimir_posordem(no *r){
    if (r != NULL)
    {
        imprimir_posordem(r->esquerda);
        imprimir_posordem(r->direita);
        printf("%d ", r->valor);
    }
}

int main(void){
    int num;
    no *raiz = NULL;

    while ((scanf("%d", &num)) == 1)
    {
        inserir(&raiz, num);
    }
    imprimir_preordem(raiz);
    printf(".\n");
    imprimir_emordem(raiz);
    printf(".\n");
    imprimir_posordem(raiz);
    printf(".\n");
    
    return 0;
}