#include <stdio.h>
#include "list_circular.c"

int main(){
    List L;
    CreateList(&L);
    insertLast(&L, 1);
    insertLast(&L, 3);
    insertLast(&L, 6);
    insertLast(&L, 5);
    insertLast(&L, 4);
    printf("Before\n");
    displayList(L);
    inverseList(&L);
    printf("\nAfter\n");
    displayList(L);
    printf("\n");
    mergeSort(&L);
    printf("\n");
    displayList(L);
    printf("\n");

    return 0;
}