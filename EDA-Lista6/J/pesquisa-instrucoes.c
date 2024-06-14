#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    int inteiro;
    char palavra[16];
} Item;

#define key(A) (A.inteiro)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(A, B)) exch(A, B);}

void insertionsort(Item *v, int l, int r){
    for (int i = r; i > l; i--)
        cmpexch(v[i], v[i-1]);
    
    for (int i = l + 2; i <= r; i++)
    {
        int j = i; Item temp = v[j];
        while (less(temp, v[j-1]))
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }
}

char *busca_binaria(Item *instrucao, int n, int key){
    int esq = 0, dir = n-1;
    while (esq <= dir) {
        int meio = (dir + esq)/2;
        if (instrucao[meio].inteiro == key){
            return instrucao[meio].palavra;
        }
        else if (instrucao[meio].inteiro < key) {
            esq = meio + 1;
        }
        else {
            dir = meio - 1;
        }
    }
    return "undefined";
}

int main(void){
    int n;
    scanf("%d", &n);

    Item instrucao[10000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &instrucao[i].inteiro, instrucao[i].palavra);
    }

    insertionsort(instrucao, 0, n-1);
    
    int pesquisa;
    while (scanf("%d", &pesquisa) != EOF) {
        printf("%s\n", busca_binaria(instrucao, n, pesquisa));
    }
    
    return 0;
}