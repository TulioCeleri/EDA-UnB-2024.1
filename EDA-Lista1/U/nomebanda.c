#include <stdio.h>
#include <string.h>

struct tipoBanda
{
    char nome[80];
    int ano;
};

struct tipoShow
{
    char nome[80];
    int qtd;
    struct tipoBanda bandas[100];
};

void pesquisarNomaBanda(char pesquisa[80], struct tipoShow shows[50], int n){
    

}

