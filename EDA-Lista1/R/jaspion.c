#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t); //Indica o número de instâncias subsequentes
    int m, n;
    char dicionario_pal[100][81];
    char dicionario_trad[100][81];
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &m, &n); //representam o número de palavras no dicionário e o número de linhas na letra da música, respectivamente
        for (int j = 0; j < m; j++) //loop para ler as palavras e suas traduções
        {
            char palavra[81];
            char traducao[81];
            scanf("%s", palavra);
            scanf(" %[^\n]s", traducao);
            if (j % 2 == 0)
            {
                strcpy(dicionario_pal[j], palavra);
            }
            else
            {
                strcpy(dicionario_trad[j], traducao);
            }
        
        }
        for (int k = 0; k < n; k++) //loop para ler as linhas da letra da música
        {
            char musica[81];
            scanf(" %[^\n]s", musica);
        } 
    }

    printf("%s\n", dicionario_pal[0]); // imprimir dicionario
    printf("%s\n", dicionario_trad[0]); // imprimir dicionario
    printf("%s\n", dicionario_pal[1]); // imprimir dicionario
    printf("%s\n", dicionario_trad[1]); // imprimir dicionario
    
    return 0;
}