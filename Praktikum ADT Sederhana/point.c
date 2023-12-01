#include <math.h>
#include <stdio.h>
#include "point.h"

void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P){
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ (POINT P1, POINT P2){
    return (Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2));
}

boolean IsOrigin (POINT P){
    return (Absis(P) == 0) && (Ordinat(P) == 0);
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
    return (Absis(P) == 0);
}

int Kuadran (POINT P){
    if (Absis(P) > 0){
        if (Ordinat(P) > 0){
            return 1;
        } else{
            return 4;
        }
    } else{
        if (Ordinat(P) > 0){
            return 2;
        } else{
            return 3;
        }
    }
}

POINT NextX (POINT P){
    Absis(P) = Absis(P) + 1;
    return P;
}         

POINT NextY (POINT P){
    Ordinat(P) = Ordinat(P) + 1;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX){
    if (SbX){
        Ordinat(P) = Ordinat(P) * (-1);
    } else{
        Absis(P) = Absis(P) * (-1);
    }
    return P;
}

float Jarak0 (POINT P){
    return sqrt(Absis(P)*Absis(P) + Ordinat(P)*Ordinat(P));
}

float Panjang (POINT P1, POINT P2){
    float diffX, diffY;
    diffX = Absis(P1) - Absis(P2);
    diffY = Ordinat(P1) - Ordinat(P2);
    return sqrt(diffX*diffX + diffY*diffY);
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}

void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
    if (SbX){
        Ordinat(*P) = (-1) * Ordinat(*P);
    } else{
        Absis(*P) = (-1) * Absis(*P);
    }
}

void Putar (POINT *P, float Sudut){
    float X, Y;
    X = Absis(*P);
    Y = Ordinat(*P);
    Sudut = (360 - Sudut) * (acos(-1) / 180);

    Absis(*P) = (cos(Sudut) * X) - (sin(Sudut) * Y);
    Ordinat(*P) = (sin(Sudut) * X) + (cos(Sudut) * Y);
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
    float a, b;
    a = (Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1));
    b = Ordinat(P2) - a*Absis(P2);
    printf("(%d,%d)", (int)a, (int)b);
}