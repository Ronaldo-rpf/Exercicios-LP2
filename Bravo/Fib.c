#include <stdio.h>
#include <stdlib.h>
int fib (int n){
    if (n <= 1){
        return 1;
    }
    int m = fib (n-1);
    int h = fib (n-2);
    return (m+h);
}

int main (){
    printf("%d \n\n", fib(4));

    return 0;
}

//    1 1 2 3 5