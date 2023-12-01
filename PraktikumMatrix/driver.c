#include <stdio.h>

int main(){
    double temp;
    double sisa;
    for (int i = 1; i <= 10; i++){
        temp = (double) 100/i;
        printf("%lf\n", temp);
    }
}