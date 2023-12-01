#include "matrix.h"
#include <stdio.h>
#include <math.h>

Matrix identityMatrix2x2(){
    Matrix M;
    createMatrix(2, 2, &M);
    ELMT(M, 0, 0) = 1;
    ELMT(M, 1, 1) = 1;
    return M;
}

Matrix PangkatMatrix(Matrix M, long long int power){
    if (power == 0) {return identityMatrix2x2();}
    else if (power == 1) {return M;}
    else{
        Matrix M2 = PangkatMatrix(M, power/2);
        Matrix mulMatrix = multiplyMatrixWithMod(M2, M2, 2003);
        if (power % 2 == 1){
            mulMatrix = multiplyMatrixWithMod(mulMatrix, M, 2003);
        }
        return mulMatrix;
    }
}

Matrix fibonacciMatrix(){
    Matrix M;
    createMatrix(2, 2, &M);
    ELMT(M, 0, 0) = 1;
    ELMT(M, 0, 1) = 1;
    ELMT(M, 1, 0) = 1;
    return M;
}

Matrix fibonacciStartMatrix(){
    Matrix M;
    createMatrix(2, 1, &M);
    ELMT(M, 0, 0) = 1;
    ELMT(M, 1, 0) = 1;
    return M;
}

int main(){
    long long int K;
    scanf("%d", &K);

    Matrix res;
    createMatrix(2, 2, &res);

    Matrix multiplier = PangkatMatrix(fibonacciMatrix(), K - 2);
    res = multiplyMatrixWithMod(multiplier, fibonacciStartMatrix(), 2003);
    printf("%d\n", ELMT(res, 0, 0));

    return 0;
}