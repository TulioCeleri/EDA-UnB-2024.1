#include <stdio.h>
#include <stdlib.h>

void ultrapassa(int v[], int tam, int lim){
  int soma = 0;
  int ultimo[tam];
  int pos = 0;

  for(int i = 0; i < tam; i++)
  {
    ultimo[i] = 0;
  }

  for(int i=0; i < tam; i++)
  {
    soma += v[i];
    
    if(soma > lim)
    {
      ultimo[pos] = v[i];
      pos++;
      soma = 0;
    }
  }

  for(int i=tam-1; i >= 0; i--)
  {
    if(ultimo[i] != 0)
    {
      printf("%d\n", ultimo[i]);
    }
  }

}


int main(){

  int *v;

  v = (int *) malloc(sizeof(int));

  int valor, tamanho = 0;
  do {
        scanf("%d", &valor);
        if (valor != 0) 
        {
            tamanho++; 
            v = (int*)realloc(v, tamanho * sizeof(int)); 
            v[tamanho - 1] = valor; 
        }
    } while (valor != 0);

  int limite;
  scanf("%d", &limite);

  ultrapassa(v, tamanho, limite);

  free(v);
  return 0;
}
