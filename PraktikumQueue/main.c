#include "queue.c"
#include <stdio.h>

int main(){
    Queue Q;
    CreateQueue(&Q);
    enqueue(&Q, 0);
    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    displayQueue(Q);
    return 0;
}