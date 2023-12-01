#include "boolean.h"
#include "datetime.h"
#include "time.h"
#include <math.h>
#include <stdio.h>

int GetMaxDay(int M, int Y){
    boolean kabisat;
    if (Y % 400 == 0){
        kabisat = true;
    } else{
        if (Y % 100 == 0){
            kabisat = false;
        } else{
            if (Y % 4 == 0){
                kabisat = true;
            } else{
                kabisat = false;
            }
        }
    }

    if ((M == 1) || (M == 3) || (M == 5) || (M == 7) || (M == 8) || (M == 10) || (M == 12)){
        return 31;
    } else if ((M == 4) || (M == 6) || (M == 9) || (M == 11)){
        return 30;
    } else if((M == 2)){
        if (kabisat){
            return 29;
        }else{
            return 28;
        }
    }
}

boolean IsKabisat(int Y){
    boolean kabisat;

    if (Y % 400 == 0){
        kabisat = true;
    } else{
        if (Y % 100 == 0){
            kabisat = false;
        } else{
            if (Y % 4 == 0){
                kabisat = true;
            } else{
                kabisat = false;
            }
        }
    }

    return kabisat;
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    return (D >= 0 && D <= GetMaxDay(M, Y)) && (M >= 0 && M <= 12) && (Y >= 1900 && Y <= 2030) && IsTIMEValid(h, m, s);
}
/* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */

/* *** Konstruktor: Membentuk sebuah DATETIME dari komponen-komponennya *** */
void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
    TIME T;
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    CreateTime(&T, hh, mm, ss);
    Time(*D) = T;
}
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaDATETIME(DATETIME *D){
    int DD, MM, YY, h, m, s;
    boolean valid = false;

    while (valid == false){
        scanf("%d%d%d%d%d%d", &DD, &MM, &YY, &h, &m, &s);

        if(IsDATETIMEValid(DD, MM, YY, h, m, s)){
            CreateDATETIME(D, DD, MM, YY, h, m, s);
            valid = true;
        } else{
            printf("Datetime tidak valid\n");
        }
    }
}
/* I.S. : D tidak terdefinisi */
/* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
/* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
/* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
    diulangi hingga didapatkan DATETIME yang valid. */
/* Contoh:
    32 13 2023 12 34 56
    DATETIME tidak valid
    31 12 2023 12 34 56
    --> akan terbentuk DATETIME <31,12,2023,12,34,56> */

void TulisDATETIME(DATETIME D){
    printf("%02d/%02d/%04d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}
/* I.S. : D sembarang */
/* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
/* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2){
    return (Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)) && TEQ(Time(D1), Time(D2));
}
/* Mengirimkan true jika D1=D2, false jika tidak */
boolean DNEQ(DATETIME D1, DATETIME D2){
    return (Day(D1) != Day(D2)) || (Month(D1) != Month(D2)) || (Year(D1) != Year(D2)) || TNEQ(Time(D1), Time(D2));
}

/* Mengirimkan true jika D1 tidak sama dengan D2 */
boolean DLT(DATETIME D1, DATETIME D2){
    if (Year(D1) > Year(D2)){
        return false;
    }else if (Year(D1) == Year(D2)){
        if (Month(D1) > Month(D2)){
            return false;
        }else if (Month(D1) == Month(D2)){
            if (Day(D1) > Day(D2)){
                return false;
            }else if (Day(D1) == Day(D2)){
                return TLT(Time(D1), Time(D2));
            }else{
                return true;
            }
        }else{
            return true;
        }
    }else{
        return true;
    }
}
/* Mengirimkan true jika D1<D2, false jika tidak */
boolean DGT(DATETIME D1, DATETIME D2){
    if (Year(D1) > Year(D2)){
        return true;
    }else if (Year(D1) == Year(D2)){
        if (Month(D1) > Month(D2)){
            return true;
        }else if (Month(D1) == Month(D2)){
            if (Day(D1) > Day(D2)){
                return true;
            }else if (Day(D1) == Day(D2)){
                return TGT(Time(D1), Time(D2));
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}
/* Mengirimkan true jika D1>D2, false jika tidak */
long long DATETIMEToDetik(DATETIME D){
    int Hari;
    long long Detik;
    boolean kabisat;

    Detik = 0;
    Hari = 0;

    for(int i = 1900; i < Year(D); i++){
        if(IsKabisat(i)){
            Hari += 366;
        } else{
            Hari += 365;
        }
    }

    for(int i = 1; i < Month(D); i++){
        Hari += GetMaxDay(i, Year(D));
    }

    Hari += Day(D) - 1;

    Detik = TIMEToDetik(Time(D));
    
    Detik += (long long) Hari * 24 * 3600;
    return Detik;
}

DATETIME DetikToDATETIME(long long seconds){
    DATETIME D;
    TIME T;
    int day, month, year;
    boolean status = true;
    
    year = 1900;

    while(status){
        if(IsKabisat(year)){
            if(seconds < 31622400){
                status = false;
            }else{
                seconds -= 31622400;
                year++;
            }
        } else{
            if(seconds < 31536000){
                status = false;
            } else{
                seconds -= 31536000;
                year++;
            }
        }
    }

    status = true;
    month = 1;
    while(status){
        if(seconds < GetMaxDay(month, year)*3600*24){
            status = false;
        } else{
            seconds -= GetMaxDay(month, year)*3600*24;
            month++;
        }
    }

    status = true;
    day = 1;
    while(status){
        if(seconds < 86400){
            status = false;
        } else{
            seconds -= 86400;
            day++;
        }
    }

    T = DetikToTIME(seconds);
    CreateDATETIME(&D, day, month, year, Hour(T), Minute(T), Second(T));
    return D;
}

DATETIME DATETIMENextNDetik(DATETIME D, int N){
    long long detikD;
    detikD = DATETIMEToDetik(D);
    detikD += N;

    return(DetikToDATETIME(detikD));
}
/* Mengirim salinan D dengan detik ditambah N

 */
DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    long long detikD;
    detikD = DATETIMEToDetik(D);
    detikD -= N;

    return(DetikToDATETIME(detikD));
}
/* Mengirim salinan D dengan detik dikurang N */
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
    return (DATETIMEToDetik(DAkh) - DATETIMEToDetik(DAw));
}
/* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
/* Prekondisi: DAkh > DAw */
