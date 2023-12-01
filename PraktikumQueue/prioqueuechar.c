#include "boolean.h"
#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
    return(Head(Q) == Nil) && (Tail(Q) == Nil);
}

boolean IsFull (PrioQueueChar Q){
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueChar Q){
    if (IsEmpty(Q)){
        return 0;
    }else{
        if (Tail(Q) >= Head(Q)){
            return Tail(Q) - Head(Q) + 1;
        } else{
            return MaxEl(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}

void MakeEmpty (PrioQueueChar * Q, int Max){
    (*Q).T = (infotype *)malloc((Max) * sizeof(infotype));
    if ((*Q).T == NULL)
    {
        MaxEl(*Q) = 0;
    }
    else
    {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }
}

void DeAlokasi(PrioQueueChar * Q){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q) = 0;
    free((*Q).T);
}

void Enqueue (PrioQueueChar * Q, infotype X){
    boolean found;
    int idx;
    int i, j;
    infotype temp;

    if (IsEmpty(*Q))
    {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else
    {
        Tail(*Q) = Tail(*Q) == MaxEl(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
        while (i != Head(*Q) && Prio(Elmt(*Q, i)) < (Prio(Elmt(*Q, j))))
        {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
        }
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X){
    if (NBElmt(*Q) == 1)
    {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) == MaxEl(*Q) - 1) ? 0 : Head(*Q) + 1;
    }
}

void PrintPrioQueueChar (PrioQueueChar Q){
infotype val;
    PrioQueueChar temp;
    temp = Q;
    if (!IsEmpty(Q))
    {
        while (!IsEmpty(temp))
        {
            Dequeue(&temp, &val);
            printf("%d %c\n", Prio(val), Info(val));
        }
    }
    printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
