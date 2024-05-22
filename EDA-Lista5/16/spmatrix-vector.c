#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int col;
    int valor;
    struct no *prox;
} no;

typedef struct matrix{
    no **linhas;
    int m, n;
} matrix;

no *cria_no(int col, int valor){
    no *novo = (no *)malloc(sizeof(no));
    novo->col = col;
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

matrix *cria_matrix(int m, int n){
    matrix *mat = (matrix *)malloc(sizeof(matrix));
    mat->linhas = (no**)malloc(m * sizeof(no*));
    for (int i = 0; i < m; i++)
    {
        mat->linhas[i] = NULL;
    }
    mat->m = m;
    mat->n = n;
    return mat;
}

void inserir(matrix *mat, int lin, int col, int valor){
    no *novo = cria_no(col, valor);
    novo->prox = mat->linhas[lin];
    mat->linhas[lin] = novo;
}

void liberaMatrix(matrix *mat){
    for (int i = 0; i < mat->m; i++)
    {
        no *atual = mat->linhas[i];
        while (atual != NULL)
        {
            no *aux = atual;
            atual = atual->prox;
            free(aux);
        }
    }
    free(mat->linhas);
    free(mat);
}

void multiplica(matrix *mat, int *vetor, int *resultado){
    for (int i = 0; i < mat->m; i++)
    {
        resultado[i] = 0;
        no *atual = mat->linhas[i];
        while (atual != NULL)
        {
            resultado[i] += atual->valor * vetor[atual->col];
            atual = atual->prox;
        }
    }
}

int main(){
    int m,n;
    scanf("%d %d", &m, &n);

    matrix *mat = cria_matrix(m, n);

    while (1)
    {
        int linha, coluna, valor;
        scanf("%d %d %d", &linha, &coluna, &valor);
        if (linha == -1 && coluna == -1 && valor == -1)
        {
            break;
        }
        inserir(mat, linha, coluna, valor);
    }

    int *vetor = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }
    
    int *resultado = (int *)malloc(m * sizeof(int));
    multiplica(mat, vetor, resultado);

    for (int i = 0; i < m; i++)
    {
        printf("%d\n", resultado[i]);
    }
    
    free(vetor);
    free(resultado);
    free(mat);

    return 0;
}