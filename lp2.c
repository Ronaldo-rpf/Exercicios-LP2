#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* geraPalavra(int tam);

int main (){
    srand (time(NULL));
    char* palavra;
    palavra = (char*) calloc (50, sizeof(char));
    palavra = geraPalavra(10);
    printf("%s\n\n", palavra);
    free(palavra);
    return 0;
}

char* geraPalavra(int tam){
    int tamanho = 2 + rand() % (tam - 1);
    char* palavra;
    palavra = (char*) calloc (tamanho, sizeof(char));
    char vetV[] = {'a', 'e', 'i', 'o', 'u'};
    char vetC[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
    
    for (int i = 0; i < tamanho; i++){
        if (i % 2 == 0){
            palavra[i] = vetC[rand() % 21];
        }
        else{
            palavra[i] = vetV[rand() % 5];
        }
    }
    return palavra;
}
