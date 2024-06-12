#include <stdio.h>

typedef long Item;
#define less(A,B) (A < B)
#define exch(A,B){Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if (less(A,B)) exch(A,B);}

void insertionsort(Item *v, int l, int r){
    for (int i = r; i > l; i--)
        cmpexch(v[i], v[i-1]);
    
    for (int i = l + 2; i <= r; i++)
    {
        int j = i; Item temp = v[j];
        while (less(temp, v[j-1]))
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }
}

int main() {
	Item v[101], placa;
	int cmd, i = 0;
	while (scanf("%d %ld", &cmd, &placa) == 2) {
		if (cmd == 1) {
			if (i < 101) {
				v[i++] = placa;
				insertionsort(v, 0, i-1);
			} else {
				if (less(placa, v[100])) {
					exch(placa, v[100]);
					insertionsort(v, 0, 100);
				}
			}
		} else {
			int n = placa;
			for (int j = 0; j < n; j++)
				printf("%ld ", v[j]);
			printf("\n");
		}
	}
	return 0;
}