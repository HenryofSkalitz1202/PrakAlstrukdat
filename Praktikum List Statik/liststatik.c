#include "boolean.h"
#include "liststatik.h"
#include <math.h>
#include <stdio.h>

void CreateListStatik(ListStatik *l){
    int i;

    for (i = IDX_MIN; i < CAPACITY; i++){
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l){
    int i = 0;

    while((i < CAPACITY) && (ELMT(l, i) != MARK)){
        i++;
    }

    return i;
}

IdxType getFirstIdx(ListStatik l){
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l){
    if (listLength(l) == 0){
        return IDX_MIN;
    } else{
        return listLength(l) - 1;
    }
}

boolean isIdxValid(ListStatik l, IdxType i){
    return ((i >= IDX_MIN) && (i < CAPACITY));
}

boolean isIdxEff(ListStatik l, IdxType i){
    return ((i >= getFirstIdx(l)) && (i <= getLastIdx(l)));
}

boolean isEmpty(ListStatik l){
    return (listLength(l) == 0);
}

boolean isFull(ListStatik l){
    return (listLength(l) == CAPACITY);
}

void readList(ListStatik *l){
    int n, i;
    ElType elm;
    scanf("%d", &n);

    while(!((n >= 0) && (n <= CAPACITY))){
        scanf("%d", &n);
    }

    CreateListStatik(l);
    for(i = IDX_MIN; i <= n-1; i++){
        scanf("%d", &elm);
        ELMT(*l, i) = elm;
    }
}

void printList(ListStatik l){
    int i;

    printf("[");
    for (i = 0; i < listLength(l); i++){
        if (i == listLength(l)-1){
            printf("%d", ELMT(l, i));
        } else{
            printf("%d,", ELMT(l, i));
        }
    }

    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    int i;
    ListStatik L;
    
    CreateListStatik(&L);
    for(i = IDX_MIN; i < listLength(l1); i++){
        if(plus){
            ELMT(L, i) = ELMT(l1, i) + ELMT(l2, i);
        } else{
            ELMT(L, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    return L;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    int i;

    if (isEmpty(l1) && isEmpty(l2)){
        return true;
    }

    if (listLength(l1) != listLength(l2)){
        return false;
    } else{
        for (i = IDX_MIN; i < listLength(l1); i++){
            if (ELMT(l1, i) != ELMT(l2, i)){
                return false;
            }
        }

        return true;
    }
}

int indexOf(ListStatik l, ElType val){
    int i;

    if (isEmpty(l)){
        return IDX_UNDEF;
    } else{
        for (i = IDX_MIN; i < listLength(l); i++){
            if (val == ELMT(l, i)){
                return i;
            }
        }

        return IDX_UNDEF;
    }
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    int i;
    ElType TempMax = ELMT(l, IDX_MIN);
    ElType TempMin = ELMT(l, IDX_MIN);

    for(i = 1; i < listLength(l); i++){
        if (ELMT(l, i) > TempMax){
            TempMax = ELMT(l, i);
        }
        
        if (ELMT(l, i) < TempMin){
            TempMin = ELMT(l, i);
        }
    }

    *max = TempMax;
    *min = TempMin;
}

void insertFirst(ListStatik *l, ElType val){
    int i;

    if(isEmpty(*l)){
        ELMT(*l, IDX_MIN) = val;
    } else{
        for(i = listLength(*l); i > 0; i--){
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, IDX_MIN) = val;
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    int i;

    for(i = listLength(*l); i > idx; i--){
        ELMT(*l, i) = ELMT(*l, i-1);
    }

    ELMT(*l, idx) = val;
}

void insertLast(ListStatik *l, ElType val){
    ELMT(*l, listLength(*l)) = val;
}

void deleteFirst(ListStatik *l, ElType *val){
    int i;
    *val = ELMT(*l, getFirstIdx(*l));

    for (i = IDX_MIN; i < getLastIdx(*l); i++){
        ELMT(*l, i) = ELMT(*l, i+1);
    }

    ELMT(*l, getLastIdx(*l)) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    int i;
    *val = ELMT(*l, idx);

    for (i = idx; i < getLastIdx(*l); i++){
        ELMT(*l, i) = ELMT(*l, i+1);
    }

    ELMT(*l, getLastIdx(*l)) = MARK;
}

void deleteLast(ListStatik *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    ELMT(*l, getLastIdx(*l)) = MARK;
}

void sortList(ListStatik *l, boolean asc){
    int i, j;
    ElType temp;

    if(asc){
        for(i = listLength(*l); i > IDX_MIN; i--){
            for(j = IDX_MIN; j < i-1; j++){
                if(ELMT(*l, j) > ELMT(*l, j+1)){
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j+1);
                    ELMT(*l, j+1) = temp;
                }
            }
        }
    } else{
        for(i = listLength(*l); i > IDX_MIN; i--){
            for(j = IDX_MIN; j < i-1; j++){
                if(ELMT(*l, j) < ELMT(*l, j+1)){
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j+1);
                    ELMT(*l, j+1) = temp;
                }
            }
        }
    }
}