#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(A, B)) exch(A, B);}

void selectionsort(Item *v, int l, int r){
    int menor;
    for (int i = l; i < r; i++)
    {
        menor = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (less(v[j],v[menor]))
            {
                menor = j;
            }
        }
        exch(v[i], v[menor]);
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

    selectionsort(vetor, 0, cont - 1);
    imprimir(vetor, 0, cont - 1);

    return 0;
}
