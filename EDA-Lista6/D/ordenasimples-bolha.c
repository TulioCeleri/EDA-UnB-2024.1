#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(A, B)) exch(A, B);}

void bubblesort(Item *v, int l, int r){
    for (int i = l; i < r; i++){
        for (int j = l; j < r; j++)
            cmpexch(v[j+1], v[j]);
    }
}

void imprimir(Item *v, int l, int r){
    for (int i = l; i < r; i++)
        printf("%d ", v[i]);

    printf("%d\n", v[r]);
}

int main(void){
    int n, cont = 0;
    Item vetor[1001];
    while (scanf("%d", &n) == 1)
    {
        vetor[cont] = n;
        cont++;
    }

    bubblesort(vetor, 0, cont - 1);
    imprimir(vetor, 0, cont - 1);

    return 0;
}
