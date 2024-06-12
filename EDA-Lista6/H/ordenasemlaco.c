#include <stdio.h>

void ordena(int *v, int n) {
    // Caso base: se o tamanho do vetor é 1 ou menor, está ordenado
    if (n <= 1) {
        return;
    }

    // Ordena os primeiros n-1 elementos
    ordena(v, n - 1);

    // Insere o n-ésimo elemento na posição correta
    int ultimo = v[n - 1];
    int j = n - 2;

    // Movendo os elementos que são maiores que o último elemento um passo à frente
    while (j >= 0 && v[j] > ultimo) {
        v[j + 1] = v[j];
        j--;
    }

    // Coloca o último elemento na posição correta
    v[j + 1] = ultimo;
}