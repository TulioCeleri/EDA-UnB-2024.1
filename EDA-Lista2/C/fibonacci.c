#include <stdio.h>

long int fibonacci(int n){
    static long int tabela[1000];   //tabela de memoização
    if (n == 1 || n == 2) return 1; //caso base
    if (tabela[n] != 0) return tabela[n]; //se já foi calculado, retorna o valor
    tabela[n] = fibonacci(n-1) + fibonacci(n-2); //calcula o valor e armazena na tabela
    return tabela[n]; //retorna o valor
}

/*
int main(){
    int a;
    a = fibonacci(11);
    printf("%d\n", a);

    return 0;
}*/