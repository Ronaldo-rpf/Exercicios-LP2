#include <stdio.h>
#include <stdlib.h>

int main (){
    int fat, n;

    scanf("%d", &fat);
    n = fat;

    for (int i=1; n-i!=0 ;i++){
        fat*= n-i;
    }

    printf("%d", fat);


    return 0;
}

