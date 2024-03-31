#include <stdio.h>

int main(){
    int i = 0;
    int x = 0;
    char str[1000];
    scanf("%s", str);

    while (str[i] != '\0') //Verificando o tamanho da string
    {
        i++;
    }

    x = i;
    for (int j = 0; j <= x; j++) //Imprimindo a string ao contrário
    {
        printf("%c", str[i]);
        i--;
    }

    return 0;
}