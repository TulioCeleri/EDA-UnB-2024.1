#include <stdio.h>

#define MAX_WORDS_S 1000
#define MAX_WORDS_P 1000
#define MAX_WORD_LEN 81

int areEqual(char s[], char p[]) {
    int i = 0;
    while (s[i] != '\0' && p[i] != '\0') {
        if (s[i] != p[i]) {
            return 0; // As strings são diferentes
        }
        i++;
    }
    // Se ambas as strings terminam ao mesmo tempo, elas são iguais
    return (s[i] == '\0' && p[i] == '\0');
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    char S[MAX_WORDS_S][MAX_WORD_LEN];
    char P[MAX_WORDS_P][MAX_WORD_LEN];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", S[i]);
    }
    
    for (int i = 0; i < M; i++) {
        scanf("%s", P[i]);
    }
    
    int found = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (areEqual(P[i], S[j])) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    
    if (found) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}

