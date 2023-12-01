#include <stdio.h>
#include "listdin.h"
#include <math.h>

int main(){
    ListDin l1,l2,l;
    int i = 0;
    CreateListDin(&l1, 100000);
    CreateListDin(&l2, 100000);
    CreateListDin(&l, 200000);
    readList(&l1);
    readList(&l2);
    while ((NEFF(l1)!=0) && (NEFF(l2)!=0)) {
        if (ELMT(l1, getFirstIdx(l1))>=ELMT(l2, getFirstIdx(l2))){
            ELMT(l, i) = ELMT(l1, getFirstIdx(l1));
            int j;
            for (j=0;j<=getLastIdx(l1);j++){
                ELMT(l1,j) = ELMT(l1,j+1);
            }
            NEFF(l1) -= 1;
            NEFF(l) += 1;
            i += 1;
        } else {
            ELMT(l, i) = ELMT(l2, getFirstIdx(l2));
            int j;
            for (j=0;j<=getLastIdx(l2);j++){
                ELMT(l2,j) = ELMT(l2,j+1);
            }
            NEFF(l2) -= 1;
            NEFF(l) += 1;
            i += 1;
        }
    }
    if (NEFF(l1) == 0){
        while (NEFF(l2)!=0){
            ELMT(l, i) = ELMT(l2, getFirstIdx(l2));
            int j;
            for (j=0;j<=getLastIdx(l2);j++){
                ELMT(l2,j) = ELMT(l2,j+1);
            }
            NEFF(l2) -= 1;
            NEFF(l) += 1;
            i += 1;
        }
    } else if (NEFF(l2) == 0) {
        while (NEFF(l1)!=0) {
            ELMT(l, i) = ELMT(l1, getFirstIdx(l1));
            int j;
            for (j=0;j<=getLastIdx(l1);j++){
                ELMT(l1,j) = ELMT(l1,j+1);
            }
            NEFF(l1) -= 1;
            NEFF(l) += 1;
            i += 1;
        }
    }
    printList(l);
    printf("\n");
    return 0;
}
