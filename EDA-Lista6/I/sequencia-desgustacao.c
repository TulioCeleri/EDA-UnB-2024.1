#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    int tamanho;
    char caractere;
    int inicio;
}Item;

#define key(A) ((A).tamanho)
#define lesseq(A,B) (key(A)<=key(B))

void merge(Item *v, int l, int r1, int r2){
    Item *v2 = malloc((r2-l+1)*sizeof(Item));
    int k = 0;
    int i = l;
    int j = r1 + 1;
    while (i <= r1 && j <= r2){
        if (lesseq(v[j], v[i])) v2[k++] = v[i++];
        else v2[k++] = v[j++];
    }
    
    while (i <= r1){
        v2[k++] = v[i++];
    }

    while (j <= r2){
        v2[k++] = v[j++];
    }
    
    k = 0;
    for (int i = l; i <= r2; i++){
        v[i] = v2[k++];
    }
    free(v2);
}

void mergesort(Item *v, int l, int r){
    if (l >= r) return;
    int meio = l+(r-l)/2;
    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int tam(char *str){
    if (*(str) == '\0') return 0;
    if (*str == *(str + 1)) return 1 + tam(str+1);
    else return 1;
}

int completa(char *str, Item *resultado, int indice, int num){
    if (str[indice] == '\0') return num;

    Item temp;
    temp.inicio = indice;
    temp.caractere = str[indice];
    temp.tamanho = tam(str+indice);

    *resultado = temp;
    completa(str, resultado+1, indice+temp.tamanho, num + 1);
}

int main(void){
    char str[100000];
    scanf("%s", str);
    Item resultados[100000];

    int num = completa(str, resultados, 0, 0);
    mergesort(resultados, 0, num - 1);

    for (int i = 0; i < num; i++)
    {
        printf("%d %c %d\n", resultados[i].tamanho, resultados[i].caractere, resultados[i].inicio);
    }
    
    return 0;
}