#include <stdlib.h>

int geraValorInt (int min, int max){
    return min + (rand()%(max-min+1));
}

float geraValorFloat (float min, float max){
    return min + (((rand()%RAND_MAX)*1.0)/RAND_MAX) * (max-min);
}

float geraValor01 (){
    return (rand()*1.0)/RAND_MAX;
}