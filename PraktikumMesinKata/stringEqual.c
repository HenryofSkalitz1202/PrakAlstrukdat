#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include <stdio.h>

int printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {

      printf("%c", word.TabWord[i]);
   }
}

int main(){
    STARTWORD();
    printf("Moving ");
    printWord(currentWord);

    ADVWORD();
    char U = 'U';
    char L = 'L';
    char R = 'R';
    char D = 'D';
    if ((char)currentWord.TabWord[4] == U){
        printf(" square upwards\n");
    } else if((char)currentWord.TabWord[4] == L){
        printf(" square leftwards\n");
    } else if((char)currentWord.TabWord[4] == R){
        printf(" square rightwards\n");
    }  else if((char)currentWord.TabWord[4] == D){
        printf(" square downwards\n");
    }

    return 0;
}
