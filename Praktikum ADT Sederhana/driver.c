#include <stdio.h>
#include "datetime.c"

int main(){
    DATETIME D1, D2;
    long long Detik1, Detik2;
    Detik1 = 0;
    Detik2 = 0;
    BacaDATETIME(&D1);
    TulisDATETIME(D1);
    printf("\n");
    BacaDATETIME(&D2);
    TulisDATETIME(D2);
    printf("\n");
    TulisDATETIME(DATETIMEPrevNDetik(D1, 5));
    printf("\n");
    TulisDATETIME(DATETIMENextNDetik(D1, 5));
    return 0;
}