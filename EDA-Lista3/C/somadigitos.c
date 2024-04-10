#include <stdio.h>
#include <stdlib.h>

int somaDigitos(char *numero) {
    
    if (*numero == '\0') { 
        return 0;
    } else {                                              
        return (*numero - '0') + somaDigitos(numero + 1); 
    }
}

int main() {
    char *numero;
    numero = (char *)malloc(100 * sizeof(char)); // Aloca memória para armazenar o número
    if (numero == NULL) {
        printf("Erro ao alocar memória.");
        return 1;
    }

    scanf("%s", numero);

    printf("%d\n", somaDigitos(numero));

    free(numero); // Libera a memória alocada
    return 0;
}
