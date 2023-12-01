#include <stdio.h>
#include "queue.h"

int main(){
    int n, k, Ni;
    Queue Q;
    scanf("%d", &n);
    scanf("%d", &k);
    int arr[k];
    CreateQueue(&Q);

    for(int i = 0; i < k; i++){
        scanf("%d", &Ni);
        arr[i] = Ni;
    }

    for(int i = k-1; i >= 0; i--){
        enqueue(&Q, arr[i]);
    }

    for(int i = k; i < n; i++){
        scanf("%d", &Ni);
        enqueue(&Q, Ni);
    }

    displayQueue(Q);
}
