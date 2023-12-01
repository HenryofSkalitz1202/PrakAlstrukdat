#include "liststatik.h"
#include <stdio.h>

int main(){
    ListStatik L1, L2;
    int i;
    int a, b;
    int multiplier;
    int jumlah, length, temp;

    readList(&L1);
    readList(&L2);

    a = 0;
    multiplier = 1;
    for (i = getLastIdx(L1); i >= 0; i--){
        a += ELMT(L1, i)*multiplier;
        multiplier *= 10;
    }

    b = 0;
    multiplier = 1;
    for (i = getLastIdx(L2); i >= 0; i--){
        b += ELMT(L2, i)*multiplier;
        multiplier *= 10;
    }

    jumlah = a + b;
    temp = jumlah;
    length = 0;
    while (temp > 0){
        length++;
        temp /= 10;
    }

    ListStatik LHasil;
    CreateListStatik(&LHasil);

    for (i = length - 1; i >= 0; i--){
        ELMT(LHasil, i) = jumlah % 10;
        jumlah /= 10;
    }

    printList(LHasil);
    printf("\n");

    return 0;
}