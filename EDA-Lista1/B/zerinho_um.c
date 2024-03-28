#include <stdio.h>

int main() {

    int jA, jB, jC;

    scanf("%d %d %d", &jA, &jB, &jC);
    
    if (jA==0){
        if (jB==1 && jC==0){
            printf("B\n");
        };
        if (jB==0 && jC==1){
            printf("C\n");
        };
        if (jB==1 && jC==1){
            printf("A\n");
        };
        if (jB==0 && jC==0){
            printf("empate\n");
        };
    };
    if (jA==1){
        if (jB==1 && jC==0){
            printf("C\n");
        };
        if (jB==0 && jC==1){
            printf("B\n");
        };
        if (jB==1 && jC==1){
            printf("empate\n");
        };
        if (jB==0 && jC==0){
            printf("A\n");
        };
    };
    
    return 0;
}