#include <stdio.h>

int main(){
    int n, m; 
    scanf("%d %d", &n, &m);//número de linhas e colunas
    int p, a, b;
    scanf("%d", &p);//número de movimentos de cada professor
    int iay = 1, iax = 1, iby = n, ibx = m;
    int encontro = 0, pos = 0, pos1 = 0, pos2 = 0;
    int saiu_PA = 0, saiu_PB = 0;
    for (int i = 0; i < p; i++)
    {
        scanf("%d %d", &a, &b); //direção tomada pelo professor
        
        if (a == 1) iay += 1;//Norte
        else if (a == 2) iay -= 1; //Sul
        else if (a == 3) iax += 1; //Leste
        else if (a == 4) iax -= 1; //Oeste

        if (b == 1) iby += 1;//Norte
        else if (b == 2) iby -= 1; //Sul
        else if (b == 3) ibx += 1; //Leste
        else if (b == 4) ibx -= 1; //Oeste

        if (iax == ibx && iay == iby) //Verifica se os professores se encontraram
        {
            pos = i+1;
            encontro = 1;
            break;
        }

        if (iax > m || iax < 1 || iay > n || iay < 1 ) //Verifica se o professor A saiu da area
        {
            pos1 = i+1;
            saiu_PA = 1;
            break;        
        }
        if (ibx > m || ibx < 1 || iby > n || iby < 1) //Verifica se o professor B saiu da area
        {
            pos2 = i+1;
            saiu_PB = 1;  
            break;
        }
               
    }
    
    if (encontro == 1)
    {
        printf("Encontraram-se na posicao (%d,%d) no passo %d\n", iax, iay, pos);
    }
    else if (saiu_PA == 1 || saiu_PB == 1)
    {
        if (saiu_PA == 1 && saiu_PB == 1)
        {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", iax, iay, pos1);
        }
        else
        {
            if (saiu_PA == 1)
            {
                printf("PA saiu na posicao (%d,%d) no passo %d\n", iax, iay, pos1);
            }
            if (saiu_PB == 1)
            {
                printf("PB saiu na posicao (%d,%d) no passo %d\n", ibx, iby, pos2);
            }
        }
    }
    else
    {
        printf("Nao se encontraram\n");
    }

    return 0;
}