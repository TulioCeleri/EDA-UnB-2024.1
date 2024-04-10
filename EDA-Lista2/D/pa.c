#include <stdio.h>

int pa_recursiva(int *v, int primeiro, int ultimo) {
    // Condição de parada: quando o índice do primeiro elemento ultrapassa o do último
    if (primeiro >= ultimo) {
        return 1; // Retorna 1, indicando que a sequência é uma PA
    }

    // Verifica se a soma dos elementos nos índices primeiro e ultimo são iguais
    if (v[primeiro] + v[ultimo] != v[primeiro + 1] + v[ultimo - 1]) {
        return 0; // Retorna 0, indicando que a sequência não é uma PA
    }

    // Chamada recursiva com os índices atualizados
    return pa_recursiva(v, primeiro + 1, ultimo - 1);
}

