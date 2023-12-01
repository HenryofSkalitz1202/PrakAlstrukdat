#include <stdio.h>
#include <stdlib.h>
#include "listlinier.c"

int main(){
    List l;
    CreateList(&l);
    insertFirst(&l, 3);
    insertAt(&l, 2, 1);
    insertAt(&l, 1, 2);
    insertAt(&l, 4, 3);
    insertLast(&l, 1);
    insertLast(&l, 4);
    displayList(l);
    reverse(&l);
    printf("\n");
    displayList(l);
    return 0;
}