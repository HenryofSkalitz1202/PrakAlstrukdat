#include "liststatik.h"
#include <stdio.h>

int countSampah(ListStatik L, int tipeSampah){
    int i, count;
    count = 0;
    for (i = 0; i < listLength(L); i++){
        if (ELMT(L, i) == tipeSampah){
            count++;
        }
    }
    return count;
}

int main(){
    ListStatik L1, L2;
    int besi, kertas, glass;
    int waktuBesi, waktuKertas, waktuGlass, waktuTotal;
    int i, count;

    readList(&L1);
    readList(&L2);

    besi = countSampah(L1, 1);
    kertas = countSampah(L1, 2);
    glass = countSampah(L1, 3);

    waktuBesi = 0;
    i = 0;
    count = 0;
    while (count < besi){
        if (ELMT(L1, i) == 1){
            waktuBesi++;
            count++;
        }
        if (i > 0){
            waktuBesi += ELMT(L2, i-1)*2;
        }
        i++;
    }

    waktuKertas = 0;
    i = 0;
    count = 0;
    while (count < kertas){
        if (ELMT(L1, i) == 2){
            waktuKertas++;
            count++;
        }
        if (i > 0){
            waktuKertas += ELMT(L2, i-1)*2;
        }
        i++;
    }

    waktuGlass = 0;
    i = 0;
    count = 0;
    while (count < glass){
        if (ELMT(L1, i) == 3){
            waktuGlass++;
            count++;
        }
        if (i > 0){
            waktuGlass += ELMT(L2, i-1)*2;
        }
        i++;
    }

    waktuTotal = waktuBesi + waktuKertas + waktuGlass;
    printf("%d\n", waktuTotal);

    return 0;
}