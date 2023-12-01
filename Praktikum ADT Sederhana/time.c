#include <math.h>
#include <stdio.h>
#include "time.h"

boolean IsTIMEValid (int H, int M, int S){
    if ((H < 0 || H > 23) || (M < 0 || M > 59) || (S < 0 || S > 59)){
        return false;
    } else{
        return true;
    }
}

void CreateTime (TIME * T, int HH, int MM, int SS){
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME(TIME* T) {
    int HH, MM, SS;
    
    do {
        scanf("%d %d %d", &HH, &MM, &SS);
        if (!IsTIMEValid(HH, MM, SS)) {
            printf("Jam tidak valid\n");
        }
    } while(!IsTIMEValid(HH, MM, SS));

    CreateTime(T, HH, MM, SS);
}

void TulisTIME (TIME T){
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T){
    return 3600*Hour(T) + 60*Minute(T) + Second(T);
}

TIME DetikToTIME (long N){
    int jam, menit, detik;
    TIME T;
    N = N % 86400;
    jam = N / 3600;
    N = N - jam*3600;
    menit = N / 60;
    detik = N - menit*60;

    CreateTime(&T, jam, menit, detik);
    return T;
}

boolean TEQ (TIME T1, TIME T2){
    return (Hour(T1) == Hour(T2)) && (Minute(T1) == Minute(T2)) && (Second(T1) == Second(T2));
}

boolean TNEQ (TIME T1, TIME T2){
    return (Hour(T1) != Hour(T2)) || (Minute(T1) != Minute(T2)) || (Second(T1) != Second(T2));
}

boolean TLT (TIME T1, TIME T2){
    return TIMEToDetik(T1) < TIMEToDetik(T2);
};

boolean TGT (TIME T1, TIME T2){
    return TIMEToDetik(T1) > TIMEToDetik(T2);
}

TIME NextDetik (TIME T){
    return(DetikToTIME(TIMEToDetik(T) + 1));
}

TIME NextNDetik (TIME T, int N){
    return(DetikToTIME(TIMEToDetik(T) + N));
}

TIME PrevDetik (TIME T){
    long detik;
    detik = TIMEToDetik(T);

    if (detik > 0){
        detik = detik - 1;
    } else{
        detik = 86399;
    }

    return DetikToTIME(detik);
}

TIME PrevNDetik (TIME T, int N){
    long detik;
    detik = TIMEToDetik(T);
    
    if (detik-N > 0){
        detik = detik - N;
    } else{
        detik = 86400 + detik - N;
    }

    return DetikToTIME(detik);
}

long Durasi (TIME TAw, TIME TAkh){
    if (TGT(TAw, TAkh)){
        return TIMEToDetik(TAkh) + 86400 - TIMEToDetik(TAw);
    } else{
        return TIMEToDetik(TAkh) - TIMEToDetik(TAw);
    }
}