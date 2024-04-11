#include <stdio.h>

int f91(int n){
    if (n <= 100)
    {
        return f91(f91(n + 11));
    }
    else
    {
        return n - 10;
    }
}

int main(void){
    int n = -1;
    while (n != 0)
    {
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        printf("f91(%d) = %d\n", n, f91(n));
    }
    return 0;
}