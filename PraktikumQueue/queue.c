#include "queue.h"
#include "boolean.h"
#include <stdio.h>

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q){
    return (length(q) == CAPACITY);
}

int length(Queue q){
    if (isEmpty(q)){
        return 0;
    } else{
        if (IDX_TAIL(q) >= IDX_HEAD(q)){
            return IDX_TAIL(q) - IDX_HEAD(q) + 1;
        } else{
            return CAPACITY - (IDX_HEAD(q) - (IDX_TAIL(q) + 1));
        }
    }
}

void enqueue(Queue *q, ElType val){
    if(isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if(length(*q) == 1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }else{
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

void displayQueue(Queue q){
    ElType head;
    int len;
    len = length(q);

    printf("[");
    for(int i = 0; i < len; i++){
        dequeue(&q, &head);

        if(i == len - 1){
            printf("%d", head);
        }else{
            printf("%d,", head);
        }
    }
    printf("]\n");
}