#include <stdio.h>

void TrocaXY(char *s, int indice){
    if (s[indice] == '\0') // Se o caractere atual for o fim da string, retorna nada
    {
        return;
    }
    else
    {
        if (s[indice] == 'x') // Se o caractere atual for 'x', imprime 'y' e chama a função recursivamente
        {
            printf("y");
            TrocaXY(s, indice + 1);
        }
        else // Se o caractere atual não for 'x', imprime o caractere atual e chama a função recursivamente
        {
            printf("%c", s[indice]);
            TrocaXY(s, indice + 1);
        }
    }
}

int main(){
    char str[81];
    scanf("%s", str);
    TrocaXY(str, 0);
    printf("\n");

    return 0;
}