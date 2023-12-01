#include "matrix.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>

boolean isSubMatrixOf(Matrix M, Matrix subM){
    boolean isSub = false;
    for(int main_row = 0; main_row < ROW_EFF(M); main_row++){
        for(int main_col = 0; main_col < COL_EFF(M); main_col++){
            if (ELMT(M, main_row, main_col) == ELMT(subM, 0, 0)){
                isSub = true;

                for(int sub_row = 0; sub_row < ROW_EFF(subM); sub_row++){
                    for(int sub_col = 0; sub_col < COL_EFF(subM); sub_col++){
                        if ((main_row + sub_row >= ROW_EFF(M)) || (main_col + sub_col >= ROW_EFF(M))){
                            isSub = false;
                            continue;
                        }

                        if (ELMT(M, main_row + sub_row, main_col + sub_col) != ELMT(subM, sub_row, sub_col)){
                            isSub = false;
                        }
                    }
                }

                if (isSub){
                    return true;
                }
            }
        }
    }

    return false;
}

int main(){
    int N, M, K, A, B;
    Matrix main, subM;
    boolean solvable = true;

    scanf("%d %d", &N, &M);
    readMatrix(&main, N, M);

    scanf("%d", &K);

    for(int i = 0; i < K; i++){
        scanf("%d %d", &A, &B);
        readMatrix(&subM, A, B);

        if (!(isSubMatrixOf(main, subM))){
            solvable = false;
            break;
        }
    }

    if (solvable){
        printf("Puzzle dapat diselesaikan.\n");
    } else{
        printf("Puzzle tidak dapat diselesaikan.\n");
    }

    return 0;
}