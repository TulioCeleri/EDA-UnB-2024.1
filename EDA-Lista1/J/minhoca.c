#include <stdio.h>

int main(){
    int n, m, soma = 0, maior = 0;
    scanf("%d %d", &n, &m);
    int matriz[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            soma += matriz[i][j];
        }

        if (soma > maior)
        {
            maior = soma;
        }
        soma = 0;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            soma += matriz[j][i];
        }

        if (soma > maior)
        {
            maior = soma;
        }
        soma = 0;
    }

    printf("%d\n", maior);


    return 0;
}