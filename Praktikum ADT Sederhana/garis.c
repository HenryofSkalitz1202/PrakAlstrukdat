#include "boolean.h"
#include "point.h"
#include "garis.h"
#include <math.h>

void CreateGaris (GARIS * L, POINT P1, POINT P2){
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS (GARIS * L){
    float X1,Y1,X2,Y2;
    POINT P1, P2;
    boolean valid = false;

    while (valid == false){
        scanf("%f %f", &X1, &Y1);
        scanf("%f %f", &X2, &Y2);
        CreatePoint(&P1, X1, Y1);
        CreatePoint(&P2, X2, Y2);

        if (EQ(P1, P2)){
            printf("Garis tidak valid\n");
        } else{
            CreateGaris(L, P1, P2);
            valid = true;
        }
    }
}

void TulisGARIS (GARIS L){
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
}

float PanjangGARIS (GARIS L){
    return Panjang(PAwal(L), PAkhir(L));
}

float Gradien (GARIS L){
    return (Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Absis(PAwal(L)));
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY){
    Absis(PAwal(*L)) += deltaX;
    Ordinat(PAwal(*L)) += deltaY;
    Absis(PAkhir(*L)) += deltaX;
    Ordinat(PAkhir(*L)) += deltaY;
}

boolean IsTegakLurus (GARIS L1, GARIS L2){
    return (Gradien(L1) * Gradien(L2) == (-1));
}

boolean IsSejajar (GARIS L1, GARIS L2){
    return (Gradien(L1) == Gradien(L2));
}

float JarakGARIS (GARIS L, POINT P){
    float a, c, d;
    int b = 1;
    a = -1 * Gradien(L);
    c = (-1 * a * Absis(PAwal(L))) - b*Ordinat(PAwal(L));
    d = fabs(a * Absis(P) + b * Ordinat (P) + c) / (sqrt(a*a + (float)b*(float)b));
    return d;
}

boolean IsPointMemenuhiGaris (GARIS L, POINT P){
    float a, b, c;
    a = Gradien(L);
    b = -1;
    c = (-1 * a * Absis(PAwal(L))) - b*Ordinat(PAwal(L));
    return (a * Absis(P) + b * Ordinat (P) + c) == 0;
}

