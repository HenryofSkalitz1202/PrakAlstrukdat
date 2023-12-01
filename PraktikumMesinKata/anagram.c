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

Word CopyToNewWord(Word word1) {

    Word word2;

    int i;
    for (i = 0; i < word1.Length; i++) {
        word2.TabWord[i] = word1.TabWord[i];
    }
    word2.Length = word1.Length;
    return word2;
}

int isWordEqual(Word word1, Word word2) {
    if (word1.Length != word2.Length) {
        return 0;
    }

    for (int i = 0; i < word1.Length; i++) {
        if (word1.TabWord[i] != word2.TabWord[i]) {
            return 0;
        }
    }

    return 1;
}

int customStrlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void customStrcpy(char *dest, const char *src, int len) {
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

int customStrcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        ++str1;
        ++str2;
    }
    return (*str1 - *str2);
}

void customQsort(char *str, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int areAnagrams(const char *str1, const char *str2) {
    int len1 = customStrlen(str1);
    int len2 = customStrlen(str2);

    if (len1 != len2) {
        return 0;
    }

    char sortedStr1[NMax];
    char sortedStr2[NMax];

    customStrcpy(sortedStr1, str1, len1);
    customStrcpy(sortedStr2, str2, len2);

    // Sort the characters in the strings
    customQsort(sortedStr1, len1);
    customQsort(sortedStr2, len2);

    // Compare the sorted strings
    return (customStrcmp(sortedStr1, sortedStr2) == 0);
}

int countAnagramsInArray(const char *word, const Word *tokens, int numTokens) {
    int count = 0;

    for (int i = 0; i < numTokens; ++i) {
        if (areAnagrams(word, tokens[i].TabWord)) {
            ++count;
        }
    }

    return count;
}

// Function to split a string based on whitespace delimiter
void splitString(const char *input, Word tokens[100], int *numTokens)
{
    *numTokens = 0;

    const char *ptr = input;
    char *tokenPtr;

    while (*ptr != '\0')
    {
        // Skip leading whitespaces
        while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
        {
            ++ptr;
        }

        if (*ptr != '\0')
        {
            // Found the beginning of a word
            tokenPtr = tokens[*numTokens].TabWord;

            // Move to the end of the word
            while (*ptr != ' ' && *ptr != '\t' && *ptr != '\n' && *ptr != '\0')
            {
                *tokenPtr++ = *ptr++;
            }

            // Null-terminate the token
            *tokenPtr = '\0';

            // Set the length of the token
            tokens[*numTokens].Length = customStrlen(tokens[*numTokens].TabWord);

            // Increase the count
            ++(*numTokens);

            // If the array is full, break to avoid overflow
            if (*numTokens == 100)
            {
                break;
            }
        }
    }
}

int main() {
    Word tokens[100];
    int numTokens;

    STARTSENTENCE();

    // Split the string into tokens
    splitString(currentWord.TabWord, tokens, &numTokens);

    int count;
    if (numTokens > 1) {
        count = countAnagramsInArray(tokens[0].TabWord, tokens + 1, numTokens - 1);
    }

    int sum = 0;
    for (int i = count; i > 0; i--){
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}