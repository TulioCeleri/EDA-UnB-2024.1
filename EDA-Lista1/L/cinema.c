/*Sua tarefa é implementar um programa que leia:
A quantidade de fileiras e de lugares por fileira que a sala de cinema possui e
Os bilhetes dos telespectadores de uma seção na sala especificada,
exibindo, ao final, um mapa da sala de cinema contendo os lugares ocupados e os lugares vazios.

A entrada é composta por várias linhas. A primeira linha contém dois números inteiros F e L ( 1 ≤ F ≤ 20 e
1 ≤ L ≤ 25, dados nessa ordem ), representando a quantidade de f ileiras e quantos lugares há por fileira na sala de cinema,
respectivamente. As N linhas seguintes ( 1 ≤ N ≤ 500 ) são os lugares correspondentes a cada bilhete recebido na entrada
da seção. O lugar é representado por uma letra maiúscula de A a T, representando a fileira, seguida de um número de 1 a
25, representando o lugar. A entrada termina com EOF.

A saída é o mapa da sala de cinema, indicando todos os lugares da sala, sendo que XX representa um lugar ocupado e
−− representa um lugar vazio.
*/

#include <stdio.h>

#define MAX_FILEIRAS 20
#define MAX_LUGARES 25

void exibirMapa(char mapa[MAX_FILEIRAS][MAX_LUGARES], int fileiras, int lugares) {
    printf("Mapa da sala de cinema:\n");
    for (int i = 0; i < fileiras; i++) {
        for (int j = 0; j < lugares; j++) {
            if (mapa[i][j] == 'X') {
                printf("XX ");
            } else {
                printf("-- ");
            }
        }
        printf("\n");
    }
}

int main() {
    int fileiras, lugares;
    char mapa[MAX_FILEIRAS][MAX_LUGARES];

    // Leitura da quantidade de fileiras e lugares
    scanf("%d %d", &fileiras, &lugares);

    // Inicializar o mapa como lugares vazios
    for (int i = 0; i < fileiras; i++) {
        for (int j = 0; j < lugares; j++) {
            mapa[i][j] = '-';
        }
    }

    // Leitura dos bilhetes e marcação dos lugares ocupados
    char fileira;
    int lugar;
    while (scanf(" %c%d", &fileira, &lugar) != EOF) {
        int indiceFileira = fileira - 'A';
        int indiceLugar = lugar - 1;
        if (indiceFileira >= 0 && indiceFileira < fileiras && indiceLugar >= 0 && indiceLugar < lugares) {
            mapa[indiceFileira][indiceLugar] = 'X';
        } else {
            printf("Bilhete inválido: %c%d\n", fileira, lugar);
        }
    }

    // Exibir o mapa da sala de cinema
    exibirMapa(mapa, fileiras, lugares);

    return 0;
}
