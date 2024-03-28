#include <stdio.h>

int main(){
    int n, x, cont = 0;
    scanf("%d", &n);
    int vet[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    scanf("%d", &x);

    for (int i = 0; i < n; i++)
    {
        if (x == vet[i])
        {
            printf("pertence\n");
            break;
        }
        
        else if (x != vet[i])
        {
            cont++;
        }
    }

    if (cont == n)
    {
        printf("nao pertence\n");
    }
    
    
    return 0;
}