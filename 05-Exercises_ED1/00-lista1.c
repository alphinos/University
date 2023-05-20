#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

float **createFMat(int n, int m){
    if (n <= 0 || m <= 0)
        return NULL;
    
    int i;
    float **mat;
    mat = (float * *) malloc(n * sizeof(float *));

    if (mat == NULL)
        return NULL;
    
    int mustFree = FALSE;
    for (i = 0; i < n; i++){
        mat[i] = (float *) malloc(m * sizeof(float));
        if (mat[i] == NULL){
            mustFree = TRUE;
            break;
        }
    }

    if (mustFree == TRUE){
        for (int j = i; j >= 0; j--){
            free(mat[j]);
        }
        free(mat);
        return NULL;
    }

    return mat;
}

int sumElmVector(int *v, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum+= v[i];
    }
    return sum;
}

float diagSumMat(float *va, int n, int m){
    int limit;
    if (n < m)
        limit = n;
    else
        limit = m;
    float sum;
    for (int i = 0; i < limit; i++){
        sum += va[i*m + i];
    }
    return sum;
}

int CmpVectorMatrix(float *vet, int n, float **ma, int m, int p){

    if (n <= 0 || m <= 0 || p <= 0)
        return FALSE;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < p; k++){
                if (vet[i] == ma[j][k]){
                    printf("Valor : %f - indice_vet : %d - indices_mat : [%d][%d]\n",
                    vet[i], i, j, k);
                }
            }
        }
    }
    return TRUE;
}

float **MultiMat(float **ma, int n, int m, float **mb, int p, int q){
    if (m != p)
        return NULL;
    float **mc = createFMat(n, q);
    float c;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < q; j++){
            c = 0;
            for (int k = 0; k < m; k++){
                c += ma[i][k] + mb[k][j];
            }
            mc[i][j] = c;
        }
    }

    return mc;
}

int typeMatrix(int **ma, int n, int m){
    int quad = 1, sim = 1, diag = 1, assim = 1;
    if (n != m){
        quad = 0;
        return -1;
    }
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j++){
            if ( ma[i][j] != ma[j][i] )
                sim = 0;
            
            if (i != j && ma[i][j] != 0)
                diag = 0;
            
            if (i != j && ma[i][j] != ma[j][i] * (-1) )
                assim = 0;
        }
    }

    if (assim == 1)
        return 3;
    if (diag == 1)
        return 2;
    if (sim == 1)
        return 1;
    if (quad == 1)
        return 0;
}

int *transp(int **ma, int n, int m){
    if (n <= 0 || m <= 0)
        return NULL;
    int *transp = (int *) malloc( n * m * sizeof(int) );
    if (transp == NULL)
        return NULL;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            transp[ j * m + i ] = ma[i][j];
        }
    }

    return transp;
}

int *multiByTransp( int **ma, int n, int m ){
    if (n <= 0 || m <= 0)
        return NULL;
    
    int *vmc = (int *) malloc(n * n * sizeof(int));
    int c;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            c = 0;
            for (int k = 0; k < m; k++){
                c += ma[i][k] + ma[k][i];
            }
            vmc[i * n + i] = c;
        }
    }

    return vmc;
}

int *rowMat(int **ma, int n, int m, int l){
    // Adotando l como o índice e não a ordem
    if (ma == NULL || n <= 0 || m <= 0 || l < 0 || l >= n)
        return NULL;
    
    return ma[l];
}

int *colMat(int **ma, int n, int m, int p){
    if (ma == NULL || n <= 0 || m <= 0 || p < 0 || p >= m)
        return NULL;
    
    int *colP = (int *) malloc( n * sizeof(int) );
    if (colP == NULL)
        return NULL;
    
    for (int i = 0; i < n; i++){
        colP[i] = ma[i][p];
    }

    return colP;
}

int *diagMat( int **ma, int n, int m ){
    if (ma == NULL || n <= 0 || m <= 0)
        return NULL;
    
    int tam;
    if (n < m)
        tam = n;
    else
        tam = m;

    int *diag = (int *) malloc( tam * sizeof(int) );
    if (diag == NULL)
        return NULL;
    
    for (int i = 0; i < tam; i++){
        diag[i] = ma[i][i];
    }

    return diag;
}

int *createIntVetWithInput(int n){
    if (n <= 0)
        return NULL;
    
    int *vet = (int *) malloc(n * sizeof(int));
    if (vet == NULL)
        return NULL;
    
    for (int i = 0; i < n; i++){
        printf("Adicione um elemento no vetor!\n");
        scanf("%d", vet[i]);
        while(getchar() != '\n');
    }

    return vet;
}



void printGreaterValue(int *v, int n){
    int greater = v[0], i;
    for ( i = 1; i < n; i++){
        if (v[i] > greater)
            greater = v[i];
    }
    printf("O maior número do vetor v é %d na posição %d!\n", greater, i);
}

void printSumN(int *v, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += v[i];
    }
    printf("A soma dos itens do vetor é: %d!\n", sum);
}

void printMiddleElm(int *v, int n){
    int i;
    if (n % 2)
        i = n/2 + 1;
    else
        i = n/2;
    
    printf("O elemento do meio é: %d no índice %d!\n", v[i], i);
}

void alg_ED1_11(){

    int n;
    printf("Por favor, indique qual o tamanho do vetor!");
    scanf("%d", &n);
    while(getchar() != '\n');
    int *vet = createIntVetWithInput(n);
    printGreaterValue(vet, n);
    printSumN(vet, n);
    printMiddleElm(vet, n);
}

int main(){

    int va[] = {0, 1, 2};
    int vb[] = {3, 4, 5};
    int vc[] = {6, 7, 8};

    int **ma = (int **) malloc( 3 * sizeof(int *) );
    ma[0] = va;
    ma[1] = vb;
    ma[2] = vc;

    int *vet = rowMat(ma, 3, 3, 1);
    for (int i = 0; i < 3; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}