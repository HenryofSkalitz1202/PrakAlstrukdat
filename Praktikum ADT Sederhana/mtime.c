#include "time.h"
#include <stdio.h>

int main()
{
    int repeat;
    TIME first, last;
    int i = 0;

    CreateTime(&first, 23, 59, 59);
    CreateTime(&last, 0, 0, 0);

    scanf("%d", &repeat);

    for (i; i < repeat; i += 1)
    {
        printf("[%d]\n", i + 1);
        TIME T1, T2;
        int durasi;
        BacaTIME(&T1);
        BacaTIME(&T2);

        if (TLT(T1, T2) == true)
        {
            durasi = Durasi(T1, T2);
            if (TLT(T1, first) == true)
            {
                first = T1;
            }
            if (TGT(T2, last) == true)
            {
                last = T2;
            }
        }
        else
        {
            durasi = Durasi(T2, T1);
            if (TLT(T2, first) == true)
            {
                first = T2;
            }
            if (TGT(T1, last) == true)
            {
                last = T1;
            }
        }
        printf("%d\n", durasi);
    }

    TulisTIME(first);
    printf("\n");
    TulisTIME(last);
    printf("\n");
    return 0;
}
