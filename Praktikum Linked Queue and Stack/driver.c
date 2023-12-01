#include <stdio.h>
#include "queuelinked.c"

int main(){
    Queue q;
    CreateQueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    printf("%d", length(q));
    DisplayQueue(q);
}