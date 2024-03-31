#include <stdio.h>

int main(){
    int n, count, maior = 0;
    char str[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        count = 0;
        while (str[count] != '\0')
        {
            count++;
        }

        if (count > maior)
        {
            maior = count;
        }
    }
    
    printf("%d\n", maior);
    return 0;
}