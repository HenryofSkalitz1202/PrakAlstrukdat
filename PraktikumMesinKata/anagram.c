#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"
#include "charmachine.h"

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

boolean compareWord(Word kata1, Word kata2) {
    int m, n;
    int len = kata1.Length;
    char temp;

    for (m = 0; m < len; m++) {
        for (n = m; n < len; n++) {
            if (kata1.TabWord[m] < kata1.TabWord[n]) {
                temp = kata1.TabWord[m];
                kata1.TabWord[m] = kata1.TabWord[n];
                kata1.TabWord[n] = temp;
            }
        }
    }

    for (m = 0; m < len; m++) {
        for (n = m; n < len; n++) {
            if (kata2.TabWord[m] < kata2.TabWord[n]) {
                temp = kata2.TabWord[m];
                kata2.TabWord[m] = kata2.TabWord[n];
                kata2.TabWord[n] = temp;
            }
        }
    }

    for (m = 0; m < len; m++) {
        if (kata1.TabWord[m] != kata2.TabWord[m]) {
            return false;
        }
    }

    return true;
}


int main()
{
    int indexArrWord = 0;
    int i, j, result = 0;
    boolean lanjut = true;
    Word arrWord[100];

    STARTWORD();
    while (!EndWord & currentChar!= MARK) {
        arrWord[indexArrWord] = currentWord;
        indexArrWord++;
        ADVWORD();
    }
    arrWord[indexArrWord] = currentWord;
    indexArrWord++;

    for (i = 0; i < indexArrWord; i++) {
        for (j = i+1; j < indexArrWord; j++) {
            if (arrWord[i].Length == arrWord[j].Length) {
                if (compareWord(arrWord[i], arrWord[j])) {
                    result++;   
                }
            }
        }
    }

    printf("%d\n",result);
    return 0;
}
