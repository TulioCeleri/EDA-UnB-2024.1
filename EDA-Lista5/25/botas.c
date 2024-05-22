#include <stdio.h>
#include <stdlib.h>

#define TAM_MIN 30
#define TAM_MAX 60
#define TAM_RANGE (TAM_MAX - TAM_MIN + 1)

int main() {
    int direito[TAM_RANGE] = {0}; 
    int esquerdo[TAM_RANGE] = {0};  
    int tamanho;
    char pe;

    // Leitura das botas até EOF
    while (scanf("%d %c", &tamanho, &pe) != EOF) {
        if (pe == 'D') {
            direito[tamanho - TAM_MIN]++;
        } else if (pe == 'E') {
            esquerdo[tamanho - TAM_MIN]++;
        }
    }

    int totalpares = 0;
    for (int i = 0; i < TAM_RANGE; i++) {
        totalpares += (direito[i] < esquerdo[i]) ? direito[i] : esquerdo[i];
    }

    printf("%d\n", totalpares);

    return 0;
}