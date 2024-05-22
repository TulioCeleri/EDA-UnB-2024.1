#include <stdio.h>
#define MAX 1001

int main(void){
    int lovemobile, topo = -1;
    int pilha[MAX];
    char resposta;
    int n;
    int aux = 1;
    while (1)
    {
        resposta = 'y';
        topo = -1;
        aux = 1;
        scanf("%d", &n);
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &lovemobile);
            if (lovemobile != aux)
            {
                pilha[++topo] = lovemobile;
            }
            else
            {
                aux++;
                if (topo != -1)
                {
                    while (pilha[topo] == aux)
                    {
                        aux++;
                        topo--;
                        if (topo == -1)
                        {
                            break;
                        }
                        
                    }
                    
                }
                
            }
            
        }
        while (topo >= 0){
            if (pilha[topo] != aux)
            {
                resposta = 'n';
            }
            topo--;
            aux++;
        }
        if (resposta == 'y')
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        
    }
    return 0;
}