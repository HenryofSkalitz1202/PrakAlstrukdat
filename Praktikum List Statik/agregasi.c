#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

int main(){
    int N, i, X, sum, max, min;
    int idx = IDX_UNDEF;
    float mean;
    ListStatik l;
    ElType elm;
    int found = 0;

    CreateListStatik(&l);

    scanf("%d", &N);
    for (i = 0; i< N; i++){
        scanf("%d", &elm);
        insertLast(&l, elm);
    }

    scanf("%d", &X);
    sortList(&l, true);

    printf("[");
    for(i = 0; i < N; i++){
        if (i == N - 1){
            printf("%d", ELMT(l, i));
        }else{
            printf("%d,", ELMT(l, i));
        }

        sum += ELMT(l, i);

        if (X == ELMT(l, i) && (found == 0)){
            idx = i;
            found = 1;
        }
    }

    printf("]\n");

    mean = (float)sum / N;
    printf("Average: %.02f\n", mean);

    if (idx == IDX_UNDEF){
        printf("%d tidak ada\n", X);
    } else{
        printf("%d\n", idx);
    }

    extremeValues(l, &max, &min);

    if(X == max){
        printf("X maksimum\n");
    }

    if(X == min){
        printf("X minimum\n");
    }

    if(N % 2 == 0){
        if (X == ELMT(l, (N/2 - 1))){
            printf("X median\n");
        }
    } else{
        if (X == ELMT(l, (N + 1)/2 - 1)){
            printf("X median\n");
        }
    }

    return 0;
}
