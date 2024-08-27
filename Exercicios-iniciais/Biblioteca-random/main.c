#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

int main (){
    srand(time(NULL));

    printf ("%d\n\n", geraValorInt(1,20));



    return 0;
}

//gcc -o app main.c random.c