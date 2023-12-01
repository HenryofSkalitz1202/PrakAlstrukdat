#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

int main(){
    int C, Q;
    ListDin l, ltemp;
    scanf("%d", &C);
    scanf("%d", &Q);

    CreateListDin(&l, C);
    CreateListDin(&ltemp, C);

    for(int i = 0; i < Q; i++){
        int tipe;
        scanf("%d", &tipe);

        if(tipe == 1){
            int x;
            scanf("%d", &x);

            insertLast(&l, x);
            CreateListDin(&ltemp, C);
            for(int i = 0; i < listLength(l); i++){
                if (ELMT(l, i) >= x){
                    insertLast(&ltemp, ELMT(l, i));
                }
            }

            copyList(ltemp, &l);
        }else{
            printf("%d\n", NEFF(l));
            printList(l);
            printf("\n");
        }
    }
    return 0;
}
