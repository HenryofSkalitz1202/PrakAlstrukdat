#include "stack.h"
#include "boolean.h"
#include <stdio.h>

int main(){
    Stack s;
    int quest, a, hasil;
    hasil = 0;

    CreateEmpty(&s);
    scanf("%d", &a);
    Push(&s, a);

    do {
        Pop(&s, &a);
        printf("fibonacci(%d)\n", a);
        if (a == 1) hasil++;
        if (a != 0 && a != 1) {
            Push(&s, a - 2);
            Push(&s, a - 1);
        }
    } while (!IsEmpty(s));
    
    printf("%d\n", hasil);
    return 0;
}
