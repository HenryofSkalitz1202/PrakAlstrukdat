#include "stack.h"
#include "wordmachine.h"
#include "charmachine.h"
#include <stdio.h>

int integerize(char c) {
    return c - '0';
}

void reduce(Stack s1, Stack s2, Stack*s3){
    int a, b;
    boolean carry = false;
    while(!IsEmpty(s1) && !IsEmpty(s2)){
        Pop(&s1, &a);
        Pop(&s2, &b);
        if(carry){
            a--;
        }
        if(a>=b){
            a -= b;
            carry = false;
        } else{
            a += 10-b;
            carry=true;
        }
        Push(s3, a);
    }

    while(!IsEmpty(s1)){
        Pop(&s1, &a);
        if(carry){
            a--;
        }
        if(a<0){
            a += 10;
            carry = true;
        } else{
            carry = false;
        }
        Push(s3, a);
    }
}

int main()
{
    Stack s1, s2, s3;
    Word listWords[100];
    infotype val;
    int countWord = 0, i;

    CreateEmpty(&s1);
    CreateEmpty(&s2);
    CreateEmpty(&s3);

    START();
    while(currentChar != MARK){
        ADVWORD();
        
        listWords[countWord] = currentWord;
        countWord++;
    }

    for (i = 0; i < listWords[0].Length; i++) {
        Push(&s1, integerize(listWords[0].TabWord[i]));
    }

    for (i = 0; i < listWords[1].Length; i++) {
        Push(&s2, integerize(listWords[1].TabWord[i]));
    }

    reduce(s1, s2, &s3);

    int count = 0;
    while(!IsEmpty(s3)){
        Pop(&s3, &i);
        if(!(i == 0 && count == 0)){
            printf("%d", i);
            count++;
        }
    }
    if(count == 0){
        printf("%d", i);
    }
    printf("\n");

    return 0;
}
