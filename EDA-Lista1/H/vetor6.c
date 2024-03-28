#include <stdio.h>

int main(){
    int n, soma = 0;
    scanf("%d", &n);
    int vet[n], vet2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet2[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        soma = vet[i] + vet2[i];
        if (i == n-1)
        {
            printf("%d\n", soma);
        }
        else
        {
            printf("%d ", soma);
        }
        
    }
    
    return 0;
}