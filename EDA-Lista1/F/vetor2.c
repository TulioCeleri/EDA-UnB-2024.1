#include <stdio.h>

int main(){
    int n, menor = 0, indice = 0;
    scanf("%d", &n);
    int vet[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (vet[i] < menor)
        {
            menor = vet[i];
            indice = i;
        }
    }
    
    printf("%d\n", indice);
    
    return 0;
}