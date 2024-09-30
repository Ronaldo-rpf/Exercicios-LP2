#include <stdio.h>
#include <stdlib.h>
#include "procimg.h"

int main (){
    unsigned char *v;

    v = geraArray1D (10);

    for (int i=0; i < 10; i++){
        printf("%u", v[i]);
    }

    free (v);
    return 0;
}

