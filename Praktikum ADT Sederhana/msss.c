#include <stdio.h>
#include "point.h"

void PrintMatrix(int a[3][4], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void GaussJordan(float a[3][4], int n){
    int flag;
    float temp;
    for (int i = 0; i < n; i++){
        //Switch rows if leading 1 is not present
        if (a[i][i] == 0) {
            int c = 1;

            while ((i + c) < n && a[i + c][i] == 0){
                c++;
            }

            for (int j = i, k = 0; k <= n; k++){
                temp = a[j][k];
                a[j][k] = a[j+c][k];
                a[j+c][k] = temp;
            }
        }

        for (int j = 0; j < n; j++) {
            // Excluding all i == j
            if (i != j) {
                 
                // Converting Matrix to reduced row echelon form(diagonal matrix)
                float pro = a[j][i] / a[i][i];
 
                for (int k = 0; k <= n; k++){               
                    a[j][k] = a[j][k] - (a[i][k]) * pro; 
                }               
            }
        }
    }
}

int main(){
    POINT P1, P2, P3;
    BacaPOINT(&P1);
    BacaPOINT(&P2);
    BacaPOINT(&P3);

    float mtrx[3][4];

    mtrx[0][0] = Absis(P1) * Absis(P1);
    mtrx[0][1] = Absis(P1);
    mtrx[0][2] = 1;
    mtrx[0][3] = Ordinat(P1);

    mtrx[1][0] = Absis(P2) * Absis(P2);
    mtrx[1][1] = Absis(P2);
    mtrx[1][2] = 1;
    mtrx[1][3] = Ordinat(P2);

    mtrx[2][0] = Absis(P3) * Absis(P3);
    mtrx[2][1] = Absis(P3);
    mtrx[2][2] = 1;
    mtrx[2][3] = Ordinat(P3);
    
    GaussJordan(mtrx, 3);

    int mtrx_final[3][4];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            mtrx_final[i][j] = ((int)mtrx[i][j]);
            if (mtrx_final[i][j] == -0){
                mtrx_final[i][j] = 0;
            }
        }
    }

    printf("%d\n", mtrx_final[2][3]);
    return 0;
}