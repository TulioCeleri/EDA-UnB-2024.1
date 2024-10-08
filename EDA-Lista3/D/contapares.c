#include <stdio.h>
#include <string.h>

int NumPares(char *s){
    if (*(s + 1) == '\0')
    {
        return 0;
    }
    else
    {
        if (*s == *(s+2))
        {
            return 1 + NumPares(s + 1);
        }
        else
        {
            return NumPares(s + 1);
        } 
    }
}

int main(){
    int n;
    char str[201];
    scanf("%s", str);

    n = NumPares(str);
    printf("%d\n", n);
    
    return 0;
}