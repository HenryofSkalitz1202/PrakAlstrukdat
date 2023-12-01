#include "matrix.h"
#include "boolean.h"

/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    return ((i >= 0) && (i < ROW_CAP)) && ((j >= 0) && (j < COL_CAP));
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
    return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m){
    return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j){
    return ((i >= 0) && (i < getLastIdxRow(m))) && ((j >= 0) && (j < getLastIdxCol(m)));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    ROW_EFF(*mOut) = ROW_EFF(mIn);
    COL_EFF(*mOut) = COL_EFF(mIn);

    *mOut = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    ElType elm;
    createMatrix(nRow, nCol, m);

    for(int i = 0; i < nRow; i++){
        for(int j = 0; j < nCol; j++){
            scanf("%d", &elm);
            ELMT(*m, i, j) = elm;
        }
    }
}

void displayMatrix(Matrix m)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
    /*KAMUS LOKAL*/
    int i, j;
    /*ALGORITMA*/

    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1)
            {
                printf(" ");
            }
        }
        if (i != ROW_EFF(m) - 1)
        {
            printf("\n");
        }
    }
    printf("\n");
}

/*
void displayMatrix(Matrix m){
    for(int i = 0; i <= getLastIdxRow(m); i++){
        for(int j = 0; j <= getLastIdxCol(m); j++){
            if (j == getLastIdxCol(m) && i != getLastIdxRow(m)){
                printf("%d\n", ELMT(m, i, j));
            } else if (j == getLastIdxCol(m) && i == getLastIdxRow(m)){
                printf("%d", ELMT(m, i, j));
            } else{
                printf("%d ", ELMT(m, i, j));
            }
        }
    }
}
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix m;

    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
    for(int i = 0; i <= getLastIdxRow(m1); i++){
        for(int j = 0; j <= getLastIdxCol(m2); j++){
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }

    return m;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix m;

    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
    for(int i = 0; i <= getLastIdxRow(m1); i++){
        for(int j = 0; j <= getLastIdxCol(m2); j++){
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }

    return m;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m;

    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
    for(int i = 0; i <= getLastIdxRow(m1); i++){
        for(int j = 0; j <= getLastIdxCol(m2); j++){
            int sum = 0;
            for(int k = 0; k <= getLastIdxCol(m1); k++){
                sum += ELMT(m1, i, k) * ELMT(m2, k, j);
            }

            ELMT(m, i, j) = sum;
        }
    }

    return m;
}

Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod){
    Matrix m;

    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
    for(int i = 0; i <= getLastIdxRow(m1); i++){
        for(int j = 0; j <= getLastIdxCol(m2); j++){
            int sum = 0;
            for(int k = 0; k <= getLastIdxCol(m1); k++){
                sum += ELMT(m1, i, k) * ELMT(m2, k, j);
            }

            ELMT(m, i, j) = sum % mod;
        }
    }

    return m;
}

Matrix multiplyByConst(Matrix m, ElType x){
    Matrix mhasil;

    createMatrix(ROW_EFF(m), COL_EFF(m), &mhasil);
    for(int i = 0; i <= getLastIdxRow(m); i++){
        for(int j = 0; j <= getLastIdxCol(m); j++){
            ELMT(mhasil, i, j) = ELMT(m, i, j) * x;
        }
    }

    return mhasil;
}

void pMultiplyByConst(Matrix *m, ElType k){
    for(int i = 0; i <= getLastIdxRow(*m); i++){
        for(int j = 0; j <= getLastIdxCol(*m); j++){
            ELMT(*m, i, j) *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
    if ((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2))){
        return false;
    }else{
        for(int i = 0; i <= getLastIdxRow(m1); i++){
            for(int j = 0; j <= getLastIdxCol(m1); j++){
                if (ELMT(m1, i, j) != ELMT(m2, i, j)){
                    return false;
                }
            }
        }

        return true;
    }
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return !(isMatrixEqual(m1, m2));
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
    return ROW_EFF(m) * COL_EFF(m);
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
    return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m){
    if (!(isSquare(m))){
        return false;
    } else{
        for(int i = 0; i <= getLastIdxRow(m); i++){
            for (int j = 0; j <= getLastIdxCol(m); j++){
                if (ELMT(m, i, j) != ELMT(m, j, i)){
                    return false;
                }
            }
        }

        return true;
    }
}

boolean isIdentity(Matrix m){
    if (!(isSquare(m))){
        return false;
    } else{
        for (int i = 0; i <= getLastIdxRow(m); i++){
            for (int j = 0; j <= getLastIdxCol(m); j++){
                if (i == j){
                    if (getElmtDiagonal(m, i) != 1){
                        return false;
                    }
                } else{
                    if (ELMT(m, i, j) != 0){
                        return false;
                    }
                }
            }
        }

        return true;
    }
}

boolean isSparse(Matrix m){
    int sparse_count = (int)(countElmt(m) * 0.05);
    int count = 0;

    for(int i = 0; i <= getLastIdxRow(m); i++){
        for(int j = 0; j <= getLastIdxCol(m); j++){
            if (ELMT(m, i, j) != 0){
                count++;
            }
        }
    }

    if (count <= sparse_count){
        return true;
    } else{
        return false;
    }
}

Matrix negation(Matrix m){
    Matrix mhasil;

    createMatrix(ROW_EFF(m), COL_EFF(m), &mhasil);
    for(int i = 0; i <= getLastIdxRow(m); i++){
        for(int j = 0; j <= getLastIdxCol(m); j++){
            ELMT(mhasil, i, j) = ELMT(m, i, j) * (-1);
        }
    }

    return mhasil;
}

void pNegation(Matrix *m){
    for(int i = 0; i <= getLastIdxRow(*m); i++){
        for(int j = 0; j <= getLastIdxCol(*m); j++){
            ELMT(*m, i, j) *= (-1);
        }
    }
}

/*Fungsi Antara*/
Matrix minor(Matrix m, int row, int col)
{
    Matrix temp;
    int temp_row = 0, temp_column;

    createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &temp);
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        if (i != row)
        {
            temp_column = 0;
            for (int j = 0; j < COL_EFF(m); j++)
            {
                if (j != col)
                {
                    ELMT(temp, temp_row, temp_column) = ELMT(m, i, j);
                    temp_column++;
                }
            }
            temp_row++;
        }
    }
    return temp;
}

float determinant(Matrix m)
{

    float det_value = 0;
    int sign = 1;

    if (ROW_EFF(m) == 1)
    {
        return ELMT(m, 0, 0);
    }

    for (int i = 0; i < COL_EFF(m); i++)
    {
        det_value += sign * ELMT(m, 0, i) * determinant(minor(m, 0, i));
        sign *= (-1);
    }
    return det_value;
}

Matrix transpose(Matrix m){
    Matrix m_tposed;

    createMatrix(ROW_EFF(m), COL_EFF(m), &m_tposed);
    for(int i = 0; i <= getLastIdxRow(m); i++){
        for(int j = 0; j <= getLastIdxCol(m); j++){
            ELMT(m_tposed, i, j) = ELMT(m, j, i);
        }
    }

    return m_tposed;
}

void pTranspose(Matrix *m){
    Matrix m_tposed;

    createMatrix(ROW_EFF(*m), COL_EFF(*m), &m_tposed);
    for(int i = 0; i <= getLastIdxRow(*m); i++){
        for(int j = 0; j <= getLastIdxCol(*m); j++){
            ELMT(m_tposed, j, i) = ELMT(*m, i, j);
        }
    }

    *m = m_tposed;
}