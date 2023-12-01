#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 281
#define ENTER '\n'
#define BLANK ' '

typedef struct
{
   char TabWord[NMax];
   int Length;
} Word;

extern boolean EndWord;
extern Word currentWord;

void IgnoreEnters();

void IgnoreBlanks();

void STARTWORD();

// void ADVWORD();

void CopyWord();

void STARTSENTENCE();

Word CopyToNewWord(Word word1);

void printWord(Word word);

void printWordNoNewLine(Word word);

boolean isWordEqual(Word word1, Word word2);

boolean isWordEqualCaseInsensitive(Word word1, Word word2);

#endif
