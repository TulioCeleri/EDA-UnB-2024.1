#include <stdio.h>
#include <stdlib.h>

typedef struct coord{
    int x,y;
}coord;

typedef struct celula{
    char tipo;
    int altura;
} celula;

int coordvalida(int x, int y, int n, int m){
    return ((x >= 0 && x < n ) && (y >= 0 && y < m));
}

int main(void){
    int n,m;
    scanf("%d %d", &n, &m);
    celula matriz[n][m];

    coord *coord_torre = calloc(n * m, sizeof(coord));
    int num_torres = 0;
    for (int i = 0; i < n; i++)
    {
        getchar();
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &matriz[i][j].tipo);
            matriz[i][j].altura = 0;
            if (matriz[i][j].tipo == 't')
            {
                coord torre = {i, j};
                coord_torre[num_torres++] = torre;
            }   
        }
    }

    for (int i = 0; i < num_torres; i++)
    {
        coord torre = coord_torre[i];
        scanf("%d", &matriz[torre.x][torre.y].altura);
    }

    int cont = 0;

    for (int i = 0; i < num_torres; i++)
    {
        int x = coord_torre[i].x;
        int y = coord_torre[i].y;
        for (int j = x - matriz[x][y].altura; j <= x + matriz[x][y].altura; j++)
        {
            for (int k = y - matriz[x][y].altura; k <= y + matriz[x][y].altura; k++)
            {
                if (!coordvalida(j,k,n,m)) continue;
                
                if (matriz[j][k].tipo == '#')
                {
                    cont++;
                    matriz[j][k].tipo = '.';
                }
                
            }
            
        }
        
    }
    printf("%d\n", cont);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c", matriz[i][j].tipo);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}