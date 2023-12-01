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

boolean compareWords(Word kata1, Word kata2) {
    int len1 = kata1.Length;
    int len2 = kata2.Length;
    int i = 0;
    
    while (i < len1 && i < len2) {
        if (kata1.TabWord[i] < kata2.TabWord[i]) {
            return false;
        } else if (kata1.TabWord[i] > kata2.TabWord[i]) {
            return true;
        }
        i++;
    }

    if (i < len1) return true;
    return 0;
}

int main() {
    int indexArrWord = 0;
    int m, n;
    Word arrWord[100], temp;

    STARTWORD();
    while (!EndWord && currentChar != MARK) {
        arrWord[indexArrWord] = currentWord;
        indexArrWord++;
        ADVWORD();
    }
    arrWord[indexArrWord] = currentWord;
    indexArrWord++;

    for (m = 0; m < indexArrWord; m++) {
        for (n = m + 1; n < indexArrWord; n++) {
            if (compareWords(arrWord[m], arrWord[n])) {
                temp = arrWord[m];
                arrWord[m] = arrWord[n];
                arrWord[n] = temp;
            }
        }
    }

    for (m = 0; m < indexArrWord; m++) {
        printWord(arrWord[m]);
        printf("\n");
    }

    return 0;
}
