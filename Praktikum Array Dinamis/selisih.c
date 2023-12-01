#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"
#include <math.h>

int main(){
    int max = 0;
    int min = 0;
    ListDin l;

    CreateListDin(&l, 100);
    readList(&l);
    extremeValues(l, &max, &min);

    if (listLength(l) <= 1){
        printf("0\n");
    }else{
        printf("%d\n", abs(max-min)+1);
    }
    return 0;
}
