#include <stdio.h>

typedef int Item;
#define key(A) (A)
#define lesseq(A, B) (key(A) <= key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(lesseq(B, A)) exch(A, B);}

int separa(Item *v, int l, int r){
    Item c = v[r];
    int j = l;

    for (int k = l; k < r; k++) {
        if (lesseq(v[k], c)) {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void quicksort(Item *v, int l, int r){
    int j;
    if (r <= l) return;

    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);

    j = separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

void imprime(Item *v, int r){
    for (int i = 0; i < r; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[r]);
}

int main(void){
    int n;
    scanf("%d", &n);
    
    Item vet[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    quicksort(vet, 0, n-1);
    imprime(vet, n-1);
    
    return 0;
}