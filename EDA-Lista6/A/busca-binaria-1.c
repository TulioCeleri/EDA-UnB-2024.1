#include <stdio.h>
#include <stdlib.h>

typedef int Key;

int busca_binaria(int *v, int l, int r, Key k){
    while (l <= r) {
        int meio = (l+r)/2;
        if (v[meio] < k) l = meio + 1;
        else r = meio - 1;
    }
    return l;
}

int main(void){
    int n, m, num;
    scanf("%d %d", &n, &m);

    int vet[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        int indice = busca_binaria(vet, 0, n-1, num);
        printf("%d\n", indice);
    }
    
    return 0;
}