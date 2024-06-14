#include <stdio.h>
#include <stdlib.h>

int procura_numero(int *casas, int n, int num_casa){
    for (int i = 0; i < n; i++) {
        if (casas[i] == num_casa)
            return i;
    }
    return -1;
}

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);

    int *casas = malloc(n * sizeof(int));
    int *encomendas = malloc(m * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &casas[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &encomendas[i]);
    }

    int pos_atual = 0;
    int tempo = 0;
    for (int i = 0; i < m; i++)
    {
        int prox_pos = procura_numero(casas, n, encomendas[i]);
        tempo += abs(prox_pos - pos_atual);
        pos_atual = prox_pos;
    }
    printf("%d\n", tempo);
    
    free(casas);
    free(encomendas);
    
    return 0;
}