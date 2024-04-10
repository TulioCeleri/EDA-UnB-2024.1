#include <stdio.h>

// Função recursiva para desenhar a régua inglesa de ordem n
void desenharRegua(int n) {
    if (n == 0) {
        return; // Condição de parada: quando n for zero, não faz nada
    } else {
        // Desenha os traços para a metade inferior da régua
        desenharRegua(n - 1);
        
        // Desenha os traços para a linha atual
        printf(".");
        for (int i = 0; i < n; i++) {
            printf("-");
        }
        printf("\n");
        
        // Desenha os traços para a metade superior da régua
        desenharRegua(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Verifica se n é válido (não negativo)
    if (n >= 0) {
        // Chama a função para desenhar a régua inglesa de ordem n
        desenharRegua(n);
    } 
    
    return 0;
}
