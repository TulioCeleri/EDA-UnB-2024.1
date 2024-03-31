#include <stdio.h>

struct tipoFiliacao 
{
    char nome[80];
    char nomeMae[80];
    char nomePai[80];
};


struct tipoFiliacao separaLinhaCSV(char linha[250]) {
    struct tipoFiliacao f;
    int i = 0;
    int j = 0;

    // Enquanto não encontrar a primeira vírgula, copia o nome
    while (linha[i] != ',') {
        f.nome[j] = linha[i];
        i++;
        j++;
    }
    f.nome[j] = '\0';

    i++;
    j = 0;
    // Enquanto não encontrar a segunda vírgula, copia o nome da mãe
    while (linha[i] != ',') {
        f.nomeMae[j] = linha[i];
        i++;
        j++;
    }
    f.nomeMae[j] = '\0';

    i++;
    j = 0;
    // Enquanto não encontrar o final da linha, copia o nome do pai
    while (linha[i] != '\0') {
        f.nomePai[j] = linha[i];
        i++;
        j++;
    }
    f.nomePai[j] = '\0';
    return f;

}


// int main() {
//     struct tipoFiliacao f = 
//         separaLinhaCSV("Pedro da Silva Pereira,Adriana da Silva,Guilherme Pereira");

//     printf("Meu nome e %s, e meu pai se chama %s\n", f.nome, f.nomePai);
//     return 0;
// }