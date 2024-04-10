#include <stdio.h>

void MoveX(char *s, int indice){
    if (s[indice] == '\0') 
    {
        return;
    }
    else
    {
        if (s[indice] == 'x') 
        {
            MoveX(s, indice + 1);
            printf("x");
        }
        else 
        {
            printf("%c", s[indice]);
            MoveX(s, indice + 1);
        }
    }
}

int main(void){
    char str[101];
    scanf("%s", str);
    MoveX(str, 0);

    return 0;
}