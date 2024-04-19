#include <stdio.h>

double CalculaPot(int a, int b){
    double res;
    if (b == 0)
    {
        return 1;
    }
    else if (b > 0)
    {
        return a * CalculaPot(a, b - 1);
    }
    else 
    {
        res = CalculaPot(a , -b);
        return (1/res);
    }
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    if (a == 0 && b <= 0)
    {
        printf("indefinido\n");
    }
    else
    {
        printf("%lf\n", CalculaPot(a, b));
    }
    
    return 0;
}