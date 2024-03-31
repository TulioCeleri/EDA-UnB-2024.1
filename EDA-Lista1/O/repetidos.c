#include <stdio.h>

int repetidos(int v[10000], int qtd, int index)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int cont = 0;
    int aux = 0;

    for (i = 0; i < qtd; i++)
    {
        scanf("%d", &v[i]);
    }

    for (i = 0; i < qtd; i++)
    {
        for (j = 0; j < qtd; j++)
        {
            if (v[i] == v[j])
            {
                cont++;
            }
        }
        if (cont > 1)
        {
            for (k = i; k < qtd; k++)
            {
                if (v[i] == v[k])
                {
                    aux++;
                }
            }
            if (aux == index)
            {
                printf("%d\n", v[i]);
                return 0;
            }
            aux = 0;
        }
        cont = 0;
    }
    printf("SEM VALOR\n");
    return 0;
}





int main(){
    int vet[10000];
    repetidos(vet, 10, 4);

    return 0;
}