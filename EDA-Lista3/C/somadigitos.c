#include <stdio.h>

int somaDigitos(int n) {
    // Caso base: se o número for menor que 10, retorna ele mesmo
    if (n < 10) {
        return n;
    } else {
        // Chamada recursiva para calcular a soma dos dígitos do número dividido por 10
        // e adicionando o último dígito do número ao resultado
        return n % 10 + somaDigitos(n / 10);
    }
}

int main() {
    int numero;
    
    // Lê o número da entrada
    scanf("%d", &numero);
    
    // Chama a função para calcular a soma dos dígitos
    int soma = somaDigitos(numero);
    
    // Imprime o resultado
    printf("%d\n", soma);
    
    return 0;
}


