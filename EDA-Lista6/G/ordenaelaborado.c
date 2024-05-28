#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define key(A) (A)
#define lesseq(A, B) (key(A) <= key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(A, B)) exch(A, B);}

void merge(Item *v, int l, int r1, int r2){
    Item *v2 = malloc(sizeof(Item) *( r2-l+1));
    int k = 0;
    int i = l;
    int j = r1 + 1;
    while (i <= r1 && j <= r2)
    {
        if (lesseq(v[i], v[j]))
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++]; 
    }
    
    while (i <= r1)
        v2[k++] = v[i++];
    
    while (j <= r2)
        v2[k++] = v[j++];

    k = 0;
    for (int i = l; i <= r2; i++)
        v[i] = v2[k++];
    free(v2);
}

void mergesort(Item *v, int l, int r){
    if (l >= r) return;
    int meio = (l+r)/2;
    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);
}

void imprimir(Item *v, int l, int r){
    for (int i = l; i < r; i++)
        printf("%d ", v[i]);

    printf("%d\n", v[r]);
}

int main(void){
    int n, elem;
    scanf("%d", &n);
    Item vetor[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elem);
        vetor[i] = elem;
    }
    
    mergesort(vetor, 0, n - 1);
    imprimir(vetor, 0, n - 1);

    return 0;
}