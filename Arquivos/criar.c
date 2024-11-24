#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    char banda[50];
    int ano;
}musicas;

musicas lista[10];
int quant = 0;

void cadastrar (){
    if (quant < 10){
        fflush(stdin);
        printf("Nome da musica: ");
        fgets(lista[quant].nome, 50, stdin);
        printf("Nome da banda: ");
        fgets(lista[quant].banda, 50, stdin);
        printf("Ano de lancamento da musica: ");
        scanf("%d", &lista[quant].ano);
        quant++;
        printf("\n\n");
    }
    else{
        printf("Limite de musicas cadastradas atingido.\n\n");
    }
    return;
}

void imprimir (){
    for (int i = 0; i < quant; i++){
        printf ("Nome: %sBanda: %sAno de lancamento: %d\n\n", lista[i].nome, lista[i].banda, lista[i].ano);
    }
    return;
}

void lerArquivo(){
    FILE *arq = fopen ("texto.txt", "r+");
    if (arq){
        fscanf(arq, "%d\n", &quant);
        for (int i = 0; i < quant; i++){
            fgets(lista[i].nome, 50, arq);
            fgets(lista[i].banda, 50, arq);
            fscanf(arq, "%d\n\n", &lista[i].ano);
        }
        fclose(arq);
    }
    else{
        printf("Erro ao tentar ler arquivo.\n\n");
    }
    return;
}

void lerArquivoB(){
    FILE *arq = fopen("textoB.txt", "rb");
    if (arq){
        fscanf(arq, "%d\n", &quant);
        fread(lista, sizeof(musicas), quant, arq);
        fclose(arq);
    }
    else{
        printf("Erro ao ler arquivo.\n\n");
    }
    return;
}

void salvarArquivo(){
    FILE *arq = fopen("texto.txt", "w+");
    if (arq){
        fprintf (arq, "%d\n", quant);
        for (int i = 0; i < quant; i++){
            fprintf (arq, "%s", lista[i].nome);
            fprintf (arq, "%s", lista[i].banda);
            fprintf (arq, "%d\n\n", lista[i].ano);
        }
        fclose(arq);
    }
    else {
        printf ("Erro ao abrir o arquivo.\n\n");
    }
    return;
}

void salvarArquivoB(){
    FILE *arq = fopen("textoB.txt", "wb");
    if (arq){
        fprintf(arq, "%d\n", quant);
        fwrite(lista, sizeof(musicas), quant, arq);
        fclose(arq);
    }
    else{
        printf("Erro ao abrir arquivo.\n\n");
    }
    return;
}

int main (){
    int aux;

    printf ("O que deseja fazer:\n1 - Adicionar musica;\n2 - Imprimir as musicas cadastradas;\n3 - Ler do arquivo;\n4 - Salvar no arquivo;\n5 - Salvar no arquivo binario;\n6 - Ler do arquivo binario;\n7 - Sair.\n");
    scanf ("%d", &aux);

    while (aux != 7){
        switch (aux){
            case 1:
                cadastrar();
                break;
            case 2:
                imprimir();
                break;
            case 3:
                lerArquivo();
                break;
            case 4:
                salvarArquivo();
                break;
            case 5:
                salvarArquivoB();
                break;
            case 6:
                lerArquivoB();
                break;
            default:
                printf("Opcao invalida.\n\n");
                break;
        }
        printf ("O que deseja fazer:\n1 - Adicionar musica;\n2 - Imprimir as musicas cadastradas;\n3 - Ler do arquivo;\n4 - Salvar no arquivo;\n5 - Salvar no arquivo binario;\n6 - Ler do arquivo binario;\n7 - Sair.\n");
        scanf ("%d", &aux);
    }
    printf("Fim do programa.\n\n");

    return 0;
}