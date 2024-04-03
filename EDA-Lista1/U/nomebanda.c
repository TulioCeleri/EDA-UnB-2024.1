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
    int existe = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < shows[i].qtd; i++)
        {
            if (strcmp(pesquisa, shows[i].bandas[j].nome) == 0)
            {
                existe = 1;
                printf("%s : ano %d\n", shows[i].bandas[j].nome, shows[i].bandas[j].ano);
                break;
            }
        
        }
        if (existe == 0)
        {
            printf("Banda nao encontrada\n");
            break;
        }
        
    }
    
}

/*
int main(){
    struct tipoShow s[3] = {
        {
            .nome = "Super Bowl",
            .qtd = 3,
            .bandas = {
                {
                    .nome = "Lady Gaga",
                    .ano = 2017
                },
                {
                    .nome = "Katy Perry",
                    .ano = 2015
                },
                {
                    .nome = "Britney Spears",
                    .ano = 2001
                }

            }
        },
        {
            .nome = "Rock in Rio",
            .qtd = 3,
            .bandas = {
                {
                    .nome = "Queen",
                    .ano = 1985
                },
                {
                    .nome = "Iron Maiden",
                    .ano = 1985
                },
                {
                    .nome = "Guns N' Roses",
                    .ano = 1991
                }

            }
        },
        {
            .nome = "Lollapalooza",
            .qtd = 3,
            .bandas = {
                {
                    .nome = "The Strokes",
                    .ano = 2005
                },
                {
                    .nome = "Arctic Monkeys",
                    .ano = 2019
                },
                {
                    .nome = "Red Hot Chili Peppers",
                    .ano = 2001
                }

            }
        }
    

    };

    pesquisarNomaBanda("Vivencia", s, 3);

    return 0;
}*/