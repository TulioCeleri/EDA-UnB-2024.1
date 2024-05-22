#include <stdio.h>
#include <stdlib.h>

typedef struct coordenadas{
    int x, y;
} coordenadas;

int validador(int x, int y){
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int MelhorCaminho(coordenadas p, coordenadas d){
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int visitados[8][8] = {0};
    coordenadas fila[64];
    int frente = 0, tras = 0;
    fila[tras++] = p;
    visitados[p.x][p.y] = 1;

    while (frente < tras)
    {
        coordenadas atual = fila[frente++];
        if (atual.x == d.x && atual.y == d.y)
        {
            return visitados[atual.x][atual.y] - 1;
        }
        for (int i = 0; i < 8; i++)
        {
            int novoX = atual.x + dx[i];
            int novoY = atual.y + dy[i];
            if (validador(novoX, novoY) && !visitados[novoX][novoY])
            {
                visitados[novoX][novoY] = visitados[atual.x][atual.y] + 1;
                fila[tras++] = (coordenadas){novoX, novoY};
            }
        }
    }
    return -1;
}

int main(void){
    char inicio[3], fim[3];
    while (scanf("%s %s", inicio, fim) != EOF)
    {
        coordenadas partida = {inicio[1] - '1', inicio[0] - 'a'};
        coordenadas destino = {fim[1] - '1', fim[0] - 'a'};
        int n = MelhorCaminho(partida, destino);
        printf("To get from %s to %s takes %d knight moves.\n", inicio, fim, n);
    }
    
    return 0;
}