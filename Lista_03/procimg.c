
unsigned char geraGreyPixel (int tipo){
    int i = rand() % 101;
    if (tipo == 0){
        return rand() % 257;
    }
    else if (tipo > 0){
        if (i <= 75){
            return 128 + (rand() % 129); 
        }
        else{
            return rand() % 129;
        }
    }
    else{
        if (i <= 75){
            return rand() % 129;
        }
        else{
            return 128 + (rand() % 129);
        }
    }
}

int pixelMax_D(unsigned char** img, int nLin, int nCol){
    unsigned char maior = img[0][0];
    for (int i=0; i < nLin; i++){
        for(int j=0; j < nCol; j++){
            if (img[i][j] > maior){
                maior = img[i][j];
            }
        }
    }
    return maior;
}

unsigned char** geraArray2D(int nLin, int nCol){
    unsigned char **aux;
    aux = (unsigned char**) calloc (nLin, sizeof(unsigned char*));
    for(int i=0; i < nLin; i++){
        aux[i] = (unsigned char*) calloc (nCol, sizeof(unsigned char));
    }
    return aux;
}

void geraImgGreyFull_D(unsigned char** img, int nLin, int nCol, unsigned char pixel){
    for (int i=0; i < nLin; i++){
        for(int j=0; j < nCol; j++){
            img[i][j] = pixel;
        }
    }
    return;
}

unsigned char* geraArray1D(int tam){
    return (unsigned char*) calloc(tam, sizeof(unsigned char));
}

void geraImgGreyB_D(unsigned char** img, int nLin, int nCol){
    for(int i=0; i<nLin; i++){
        for (int j=0; j<nCol; j++){
            img[i][j] = 0;
        }
    }
    return;
}

void geraImgGreyW_D(unsigned char** img, int nLin, int nCol){
    for(int i=0; i<nLin; i++){
        for (int j=0; j<nCol; j++){
            img[i][j] = 255;
        }
    }
    return;
}

void geraImgGrey_D(unsigned char** img, int nLin, int nCol, int tipo){
    for(int i=0; i<nLin; i++){
        for (int j=0; j<nCol; j++){
            img[i][j] = geraGreyPixel(tipo);
        }
    }
    return;
}

int pixelMin_D(unsigned char** img, int nLin, int nCol){
    unsigned char menor = img[0][0];
    for(int i=0; i<nLin; i++){
        for (int j=0; j<nCol; j++){
            if (img[i][j] < menor){
                menor = img[i][j];
            }
        }
    }
    return menor;
}

unsigned char* somaPorLinhas_D(unsigned char** img, int nLin, int nCol){
    unsigned char *vet = geraArray1D(nLin);
    for (int i = 0; i<nLin; i++){
        for (int j = 0; j<nCol; j++){
            vet[i] += img[i][j];
        }
    }
    return vet;
}

unsigned char* somaPorColunas_D(unsigned char** img, int nLin, int nCol){
    unsigned char *vet = geraArray1D(nCol);
    for (int i = 0; i<nLin; i++){
        for (int j = 0; j<nCol; j++){
            vet[j] += img[i][j];
        }
    }
    return vet;
}

int somaTotal_R(unsigned char** img, int nLin, int nCol){
    int soma = 0;
    for (int i=0; i<nLin; i++){
        for (int j=0; j<nCol; j++){
            soma += img[i][j];
        }
    }
    return soma;
}

int quantosPixelsNaInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    int qntd = 0;
    for (int i=0; i<nLin; i++){
        for (int j=0; j<nCol; j++){
            if (img[i][j] == inten){
                qntd++;
            }
        }
    }
    return qntd;
}

int quantosPixelsAbaixoDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    int qntd = 0;
    for (int i=0; i<nLin; i++){
        for (int j=0; j<nCol; j++){
            if (img[i][j] < inten){
                qntd++;
            }
        }
    }
    return qntd;
}

int quantosPixelsAcimaDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten){
    int total = nLin*nCol, qntd;
    qntd = total - (quantosPixelsNaInt_D(img, nLin, nCol, inten) + quantosPixelsAbaixoDeInt_D(img, nLin, nCol, inten));
    return qntd;
}





