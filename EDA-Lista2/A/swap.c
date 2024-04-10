#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;  
    *a = *b;
    *b = temp;
}

/*
int main() {
    int a = 10, b = 20;
    printf("Antes do swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("Depois do swap: a = %d, b = %d\n", a, b);
    return 0;
}*/