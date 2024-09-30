unsigned char* geraArray1D(int tam);

unsigned char** geraArray2D(int nLin, int nCol);

void geraImgGreyFull_D(unsigned char** img, int nLin, int nCol, unsigned char pixel);

int pixelMax_D(unsigned char** img, int nLin, int nCol);

unsigned char geraGreyPixel (int tipo);

void geraImgGreyB_D(unsigned char** img, int nLin, int nCol);

void geraImgGreyW_D(unsigned char** img, int nLin, int nCol);

void geraImgGrey_D(unsigned char** img, int nLin, int nCol, int tipo);

int pixelMin_D(unsigned char** img, int nLin, int nCol);

unsigned char* somaPorLinhas_D(unsigned char** img, int nLin, int nCol);

unsigned char* somaPorColunas_D(unsigned char** img, int nLin, int nCol);

int somaTotal_R(unsigned char** img, int nLin, int nCol);

int quantosPixelsNaInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten); 

int quantosPixelsAbaixoDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten);

int quantosPixelsAcimaDeInt_D(unsigned char** img, int nLin, int nCol, unsigned char inten);