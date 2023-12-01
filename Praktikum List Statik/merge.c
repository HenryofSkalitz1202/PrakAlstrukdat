#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main(){
    ListStatik l1;
    int a, b, i;
    int elm;
    scanf("%d", &a);

    CreateListStatik(&l1);
    for (i = 0; i < a; i++){
        scanf("%d", &elm);
        ELMT(l1, i) = elm;
    }

    scanf("%d", &b);
    for(i = a; i < a+b; i++){
        scanf("%d", &elm);
        ELMT(l1, i) = elm;
    }

    sortList(&l1, true);
    printf("[");
    for(i = 0; i < listLength(l1); i++){
        if (i == listLength(l1) - 1){
            printf("%d", ELMT(l1, i));
        }else{
            printf("%d,", ELMT(l1, i));
        }
    }

    printf("]\n");
    return 0;
}
