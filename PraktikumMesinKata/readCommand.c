#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

void IgnoreEnters() {
    while (currentChar == '\n')
    {
        ADV();
    }
}

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
        if (word.TabWord[i] != '\0') {
            printf("%c", word.TabWord[i]);
        }
   }   
   printf("\n");
}

void CopySentence() {
    int i; 
    i = 0;
    while ((currentChar != MARK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADV();  
        i++;
    }
    currentWord.TabWord[i] = '\0';
    currentWord.Length = i;
}

void STARTSENTENCE() {

    START();
    IgnoreBlanks();
    IgnoreEnters();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopySentence();
    }

}

int main(){
    STARTSENTENCE();
    printWord(currentWord);
    printf("%d\n", currentWord.Length);

    return 0;
}