#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
    Address p = (Address)malloc(sizeof (ElmtList));

    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
        return p;
    } else{
        return NULL;
    }
}
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void deallocate(Address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
    Address p = FIRST(l);
    Address search = NULL;
    boolean found = false;

    while ((NEXT(p) != FIRST(l)) && !(found)){
        if (INFO(p) == val){
            found = true;
            search = p;
        } else{
            p = NEXT(p);
        }
    }

    //cek last element
    if(!found){
        if(INFO(p) == val){
            search = p;
        }
    }

    return search;
}
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

boolean addrSearch(List l, Address p){
    Address q = FIRST(l);
    boolean found = false;

    while ((NEXT(q) != FIRST(l)) && !(found)){
        if (q == p){
            found = true;
        } else{
            q = NEXT(q);
        }
    }

    //cek last element
    if(!found){
        if(q == p){
            found = true;
        }
    }

    return found;
}
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p = allocate(val);
    Address q = FIRST(*l);
    
    if(p != NULL){
        if (isEmpty(*l)){
            FIRST(*l) = p;
            NEXT(FIRST(*l)) = FIRST(*l);
        } else{
            while(NEXT(q) != FIRST(*l)){
                q = NEXT(q);
            }

            NEXT(q) = p;
            NEXT(p) = FIRST(*l);
            FIRST(*l) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
void insertLast(List *l, ElType val){
    Address p = allocate(val);
    Address q = FIRST(*l);
    
    if(p != NULL){
        if (isEmpty(*l)){
            FIRST(*l) = p;
            NEXT(FIRST(*l)) = FIRST(*l);
        } else{
            while(NEXT(q) != FIRST(*l)){
                q = NEXT(q);
            }

            NEXT(q) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
    Address p = FIRST(*l);
    Address q = p;

    *val = INFO(p);

    if (NEXT(FIRST(*l)) == FIRST(*l)){
        FIRST(*l) = NULL;
    } else{
        while(NEXT(p) != FIRST(*l)){
            p = NEXT(p);
        }

        FIRST(*l) = NEXT(q);
        NEXT(p) = FIRST(*l);
        deallocate(q);
    }
}
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama list l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Alamat elemen terakhir di-dealokasi */
void deleteLast(List *l, ElType * val){
    Address p = FIRST(*l);
    Address q = NEXT(p);

    *val = INFO(p);
    if (NEXT(FIRST(*l)) == FIRST(*l)){
        FIRST(*l) = NULL;
    } else{
        while(NEXT(q) != FIRST(*l)){
            p = NEXT(p);
            q = NEXT(q);
        }

        *val = INFO(q);
        NEXT(p) = FIRST(*l);
        deallocate(q);
    }
}
/* I.S. list tidak kosong */
/* F.S. x adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen pertama yg lama, jika ada */
/*      Alamat elemen terakhir di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address p = FIRST(l);

    printf("[");

    if (!isEmpty(l))
    {
        while (NEXT(p) != FIRST(l))
        {
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        printf("%d", INFO(p));
    }

    printf("]");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int sum = 0;
    Address p = FIRST(l);

    if (!isEmpty(l)){
        while(NEXT(p) != FIRST(l)){
        sum++;
        p = NEXT(p);
        }

        sum++;
    }

    return sum;
}

ElType maxValue(List l)
{
    /* Mengirimkan nilai info(P) yang maksimum */
    // KAMUS LOKAL
    ElType max_val = INFO(FIRST(l));
    Address p = FIRST(l);
    // ALGORITMA
    while (NEXT(p) != FIRST(l))
    {
        if (INFO(p) > max_val)
        {
            max_val = INFO(p);
        }
        p = NEXT(p);
    }

    if (INFO(p) > max_val){
        max_val = INFO(p);
    }

    return max_val;
}

Address adrMax(List l)
{
    /* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
    // KAMUS LOKAL
    ElType max_val = INFO(FIRST(l));
    Address p = FIRST(l);
    Address q;
    // ALGORITMA
        while (NEXT(p) != FIRST(l))
    {
        if (INFO(p) > max_val)
        {
            q = p;
            max_val = INFO(p);
        }
        p = NEXT(p);
    }

    if (INFO(p) > max_val){
        q = p;
        max_val = INFO(p);
    }

    return q;
}

ElType minValue(List l)
{
    /* Mengirimkan nilai info(P) yang minimum */
    // KAMUS LOKAL
    ElType min_val = INFO(FIRST(l));
    Address p = FIRST(l);
    // ALGORITMA
    while (NEXT(p) != FIRST(l))
    {
        if (INFO(p) < min_val)
        {
            min_val = INFO(p);
        }
        p = NEXT(p);
    }

    if (INFO(p) < min_val){
        min_val = INFO(p);
    }

    return min_val;
}

Address adrMin(List l)
{
    /* Mengirimkan address P, dengan info(P) yang bernilai minimum */
    // KAMUS LOKAL
    ElType min_val = INFO(FIRST(l));
    Address p = FIRST(l);
    Address q;
    // ALGORITMA
    while (NEXT(p) != FIRST(l))
    {
        if (INFO(p) < min_val)
        {
            q = p;
            min_val = INFO(p);
        }
        p = NEXT(p);
    }

    if (INFO(p) < min_val){
        q = p;
        min_val = INFO(p);
    }
    
    return q;
}

float average(List l){
    int sum;
    Address p = FIRST(l);
    sum = 0;

    while (NEXT(p) != FIRST(l))
    {
        sum += INFO(p);
        p = NEXT(p);
    }

    //last element
    sum += INFO(p);

    return ((float) sum/length(l));
}

void deleteAll(List *l)
{
    // KAMUS LOKAL
    ElType val;

    // ALGORITMA
    while (!isEmpty(*l))
    {
        deleteLast(l, &val);
    }
}

void copyList(List *l1, List *l2)
{
    *l2 = *l1;
}

void inverseList(List *l){
    if(!isEmpty(*l)){
        Address prev = NULL;
        Address current = FIRST(*l);
        Address next;

        do{
            next = NEXT(current);
            NEXT(current) = prev;
            prev = current;
            current = next;
        } while (current != FIRST(*l));

        NEXT(FIRST(*l)) = prev;
        FIRST(*l) = prev;
    }
}

List concat(List l1, List l2){
    List l3;
    CreateList(&l3);
    Address p = FIRST(l1);

    while(NEXT(p) != FIRST(l1)){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    insertLast(&l3, INFO(p));


    p = FIRST(l2);
    while (NEXT(p) != FIRST(l2)){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    insertLast(&l3, INFO(p));

    return l3;
}

void splitList(List source, List* front, List* back){
/* Fungsi untuk memecah sebuah list dengan head source menjadi dua buah 
   list baru, yaitu front dan back. Apabila panjang list ganjil, maka
   list front akan lebih panjang dibandingkan list back.
   Sebagai contoh untuk list dengan panjang 5, maka list front memiliki
   3 elemen dan list back memiliki 2 elemen.
*/
    CreateList(front);
    CreateList(back);
    Address ElAddress = FIRST(source);
    double midIdx = (double)length(source)/2;
    int idx = 0;

    while(NEXT(ElAddress) != FIRST(source)){
        if(idx >= midIdx){
            insertLast(back, INFO(ElAddress));
        }
        else{
            insertLast(front, INFO(ElAddress));
        }
        ElAddress = NEXT(ElAddress);
        idx++;
    }
    insertLast(back, INFO(ElAddress));

    
}

List merge(List a, List b){
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/
    if (isEmpty(a)) {return b;}
    else if (isEmpty(b)) {return a;}
    else {
        List res;
        List list_temp;
        ElType temp;
        CreateList(&res);
        CreateList(&list_temp);
        if (INFO(FIRST(a)) < INFO(FIRST(b))){
            insertLast(&res, INFO(FIRST(a)));
            copyList(&a, &list_temp);
            deleteFirst(&list_temp, &temp);
            return concat(res, merge(list_temp, b));
        }
        else{
            insertLast(&res, INFO(FIRST(b)));
            copyList(&b, &list_temp);
            deleteFirst(&list_temp, &temp);
            return concat(res, merge(a, list_temp));
        }
    }
}

void mergeSort(List* list){
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Setiap kali fungsi dipanggil, maka tampilkan list yang sekarang
   sedang diproses.
   Apabila head atau NEXT(head) kosong, maka lakukan return
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian 
   secara rekursif melakukan merge untuk mengurutkan
*/

    displayList(*list);
    printf("\n");
    if (length(*list) < 2){
        return;
    }

    List front;
    List back;
    splitList(*list, &front, &back);
    mergeSort(&front);
    mergeSort(&back);
    *list = merge(front, back);
}