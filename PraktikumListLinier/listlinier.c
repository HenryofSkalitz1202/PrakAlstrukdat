#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val){
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }

    return p;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    Address p = l;

    for(int i = 0; i < idx; i++){
        p = NEXT(p);
    }

    return INFO(p);
}

/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    Address p = *l;

    for(int i = 0; i < idx; i++){
        p = NEXT(p);
    }

    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    int idx = 0;
    boolean found = false;
    Address p = l;

    while ((p != NULL) && !(found)){
        if (INFO(p) == val){
            found = true;
        }else{
            idx++;
            p = NEXT(p);
        }
    }

    if (found){
        return idx;
    }else{
        return IDX_UNDEF;
    }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p = newNode(val);

    if(p != NULL){
        NEXT(p) = *l;
        *l = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    if (isEmpty(*l)){
        insertFirst(l, val);
    } else{
        Address p = newNode(val);

        if (p != NULL){
            Address last = *l;
            while(NEXT(last) != NULL){
                last = NEXT(last);
            }

            NEXT(last) = p;
        }
    }
}

/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    if (idx == 0){
        insertFirst(l, val);
    } else{
        Address p = newNode(val);

        if (p != NULL){
            Address loc = *l;

            for(int ctr = 0; ctr < idx-1; ctr++){
                loc = NEXT(loc);
            }

            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address p = *l;

    *val = INFO(*l);
    *l = NEXT(*l);
    free(p);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */

void deleteLast(List *l, ElType *val){
    Address p = *l;
    Address loc = NULL;

    while (NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }

    if (loc == NULL){
        *l = NULL;
    } else{
        NEXT(loc) = NULL;
    }

    *val = INFO(p);
    free(p);
}
/* I.S. list mungkin kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    if (idx == 0){
        deleteFirst(l, val);
    } else{
        Address loc = *l;
        for(int ctr = 0; ctr < idx-1; ctr++){
            loc = NEXT(loc);
        }

        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    printf("[");

    if(!(isEmpty(l))){
        while(NEXT(l) != NULL){
            printf("%d,", INFO(l));
            l = NEXT(l);
        }

        printf("%d", INFO(l));
    }

    printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int ctr = 0;
    Address p = l;

    while(p != NULL){
        ctr++;
        p = NEXT(p);
    }

    return ctr;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
    List l3;
    CreateList(&l3);
    Address p = l1;

    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = l2;
    while (p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    return 0;
}

//SEARCH ELEMEN
boolean fSearch(List l, Address p)
{
    Address q = l;
    boolean found = false;

    while ((q != NULL) && (!found))
    {
        if (INFO(q) == INFO(p))
        {
            found = true;
        }
        q = NEXT(q);
    }
    return found;
}

Address searchPrec(List l, ElType x)
{
    int idx = indexOf(l, x);
    Address p = l;
    Address q;
    int i;

    if (idx == IDX_UNDEF)
    {
        return NULL;
    }
    else
    {
        if (idx == 0)
        {
            return NULL;
        }
        else
        {
            for (i = 0; i < idx; i++)
            {
                p = NEXT(p);
            }
            return p;
        }
    }
}

ElType maxValue(List l)
{
    /* Mengirimkan nilai info(P) yang maksimum */
    // KAMUS LOKAL
    ElType max_val = INFO(l);
    Address p = l;
    // ALGORITMA
    while (p != NULL)
    {
        if (INFO(p) > max_val)
        {
            max_val = INFO(p);
        }
        p = NEXT(p);
    }
    return max_val;
}

Address adrMax(List l)
{
    /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    // KAMUS LOKAL
    ElType max = INFO(l);
    Address p = l;
    Address q;
    // ALGORITMA
    while (p != NULL)
    {
        if (INFO(p) > max)
        {
            q = p;
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return q;
}

ElType minValue(List l)
{
    /* Mengirimkan nilai info(P) yang minimum */
    // KAMUS LOKAL
    ElType min_val = INFO(l);
    Address p = l;
    // ALGORITMA
    while (p != NULL)
    {
        if (INFO(p) < min_val)
        {
            min_val = INFO(p);
        }
        p = NEXT(p);
    }
    return min_val;
}

Address adrMin(List l)
{
    /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    // KAMUS LOKAL
    ElType min = INFO(l);
    Address p = l;
    Address q;
    // ALGORITMA
    while (p != NULL)
    {
        if (INFO(p) < min)
        {
            q = p;
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return q;
}

float average(List L){
    int sum;

    sum = 0;
    for (int i = 0; i < length(L); i++){
        sum += getElmt(L, i);
    }

    return ((float) sum/length(L));
}
/* Mengirimkan nilai rata-rata info(P) */
// Proses terhadap semua elemen list

void deleteAll(List *l)
{
    // KAMUS LOKAL
    Address p = *l;
    ElType val;
    // ALGORITMA
    while (!isEmpty(*l))
    {
        deleteLast(l, &val);
    }
}

void copyList(List *l1, List *l2)
{
    // KAMUS LOKAL
    Address p = *l1;
    // ALGORITMA
    *l2 = *l1;
}

void inverseList(List *l){
    Address next, prev, current;
    next = NULL;
    prev = NULL;
    current = *l;

    while (current != NULL) {
        next = NEXT(current);

        NEXT(current) = prev;

        prev = current;
        current = next;
    }
    FIRST(*l) = prev;
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
