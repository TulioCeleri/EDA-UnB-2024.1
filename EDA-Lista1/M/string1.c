#include <stdio.h>

int main(){
    int i = 0;
    char str[1000];
    scanf("%s", str);
    
    while (str[i] != '\0')
    {
        i++;
    }
    
    printf("%d\n", i);

    return 0;
}