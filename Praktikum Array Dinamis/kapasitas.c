#include <stdio.h>
#include "listdin.h"
#include <math.h>

int main(){
    ElType trash;
    ListDin l;
    CreateListDin(&l, 0);
    int tipe, q;
    scanf("%d", &q);
    for (int i=1;i<=q;i++){
        scanf("%d",&tipe);
        if(tipe==1){
            int x;
            scanf("%d",&x);
            if (CAPACITY(l)==0){
                expandList(&l, 1);
                insertLast(&l, x);
            } else {
                if (CAPACITY(l)==NEFF(l)){
                    expandList(&l, CAPACITY(l));
                    insertLast(&l, x);
                } else {
                    insertLast(&l, x);
                }
            }
        }else if(tipe==2){
            deleteLast(&l, &trash);
            if (NEFF(l)<=(round(CAPACITY(l)/2))){
                ListDin lNew;
                CreateListDin(&lNew, round(CAPACITY(l)/2));
                NEFF(lNew) = NEFF(l);
                IdxType i;
                for (i= getFirstIdx(l); i<= getLastIdx(l); i++){
                ELMT(lNew, i) = ELMT(l,i);
                }
                dealocateList(&l);
                l = lNew;
            }
        }else{
            printf("%d ", CAPACITY(l));
            printList(l);
            printf("\n");
        }
    }
    return 0;
}
