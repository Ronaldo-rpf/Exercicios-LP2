#include <stdio.h>
#include <stdlib.h>

void maxm(int, int);

int a[10] = {2,3,4,5,-10,200,150,301,1000,-34};

int main (){
    
    maxm(1,10);

    for(int i=0; i<10; i++){
        printf("%d\n", a[i]);
    }

    return 0;
}

void maxm (int m, int n){
    int temp, flag = 1;

    while (flag){
        flag=0;
        for (int i=m-1; i<n-1; i++){
            if(a[i] < a[i+1]){
                flag=1;
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
}