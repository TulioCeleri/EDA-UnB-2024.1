#include <stdio.h>

int main(int argc, char **argv){
    printf("%d\n", argc - 1); // argc - 1 para desconsiderar o nome do programa
    
    for (int i = 1; i < argc; i++) // loop para imprimir os argumentos
    {
        printf("%s\n", argv[i]);
    }
    
  return 0;
}