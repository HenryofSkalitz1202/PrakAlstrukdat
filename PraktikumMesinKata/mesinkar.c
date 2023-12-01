#include "mesinkar.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()
{

    pita = stdin;
    ADV();

}

void ADV()
{

    retval = fscanf(pita, "%c", &currentChar);

}

char toUpperCase(char c) {

    if (c >= 90) {
            c += 32;
    }

    return c;

}

char toLowerCase(char c) {

    if (c >= 90) {
            c += 32;
    }

    return c;

}
