#include <stdio.h>
#include "matrix.h"

int main(){
    int hitam = 0, putih = 0;
    Matrix m;
    ElType elm;

    createMatrix(8, 8, &m);
    for (int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            scanf("%d", &elm);
            if (elm == 1){
                if((i+j) % 2 == 0){
                    hitam++;
                }else{
                    putih++;
                }
            }
        }
    }

    printf("%d %d\n", hitam, putih);
    return 0;
}
