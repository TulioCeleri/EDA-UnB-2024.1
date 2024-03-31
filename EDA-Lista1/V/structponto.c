#include <stdio.h>
#include <math.h>

struct tipoPonto
{
    double x;
    double y;
};

double distancia(struct tipoPonto pa, struct tipoPonto pb) {
    double d;
    d = sqrt((pow(pb.x-pa.x, 2))+(pow(pb.y-pa.y, 2)));
    return d;
}
/*
int main(){
    
    struct tipoPonto p1 = {
        .x = 4,
        .y = 3
    };
    struct tipoPonto p2 = {
        .x = 3,
        .y = -2
    };

    printf("%.4lf\n", distancia(p1, p2));
    return 0;
}*/