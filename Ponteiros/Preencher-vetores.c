#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherA(float *, int, float, float);

int main () {
    int n;
    srand(time(NULL)); 

    printf("Tamanho do vetor: ");
    scanf("%d", &n);

    float vetor[n];

    preencherA(vetor, n, 1, 4);

    for(int i = 0; i < n; i++){
        printf("%f\n", vetor[i]);
    }
    
    return 0;
}

void preencherA (float vetor[], int n, float min, float max){
    if (n == 0){
        return;
    }
    vetor[n-1] = min + (float)rand() / RAND_MAX * (max-min);
    preencherA(vetor, n-1, min, max);
}