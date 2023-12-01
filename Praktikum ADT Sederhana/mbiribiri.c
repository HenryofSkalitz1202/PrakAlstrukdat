#include "boolean.h"
#include "point.h"
#include "garis.h"
#include <math.h>
#include <stdio.h>

int main(){
    int b, n;
    int jumlah = 0;
    GARIS L;
    POINT P;

    scanf("%d", &b);
    BacaGARIS(&L);

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        BacaPOINT(&P);
        if(JarakGARIS(L, P) <= b){
            jumlah++;
        }
    }

    printf(("%d\n"), jumlah);
    return 0;
}
