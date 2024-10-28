#include <stdio.h>
#include <stdlib.h>

int a[10] = {3,8,-1,100,4,2,45,23,77,12};

int maxm (int m, int n){
    if (n==m){
        return (a[m]);
    }
    if (a[m] < a[n]){
        int temp = a[m];
        a[m] = a[n];
        a[n] = temp;
    }
    return maxm(m, n-1);
}

int minm (int m, int n){
    if (m==n){
        return (a[m]);
    }
    if (a[m] > a[n]){
        int temp = a[m];
        a[m] = a[n];
        a[n] = temp;
    }
    return minm (m, n-1);
}

int ordnc (int m, int n){
    int flag = 1;
    for (int i = m; i != n; i++){
        if (a[i] < a[i+1]){
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            flag=0;
        }
    }
    if (flag){
        return (a[m]);
    }
    return ordnc(m, n-1);
}

int main (){
    for(int i=0;i<10;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    int menor = ordnc(0, 9);
    printf("\n");
    printf("%d\n", menor);
    for(int i=0;i<10;i++){
        printf("%d ", a[i]);
    }

    return 0;
}