#include <stdio.h>
#include <stdlib.h>

void parametro (int *);

int main (){
    int *p;
    int x;
    p = &x;
    x = 3;
    
    printf ("%d\n\n", *p);
    printf ("%d\n\n", x);

    parametro(&x);

    printf ("%d\n\n", *p);
    printf ("%d\n\n", x);

    return 0;
}

void parametro (int *a){
    *a = 8;
    return;
}