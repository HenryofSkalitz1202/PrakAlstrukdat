#include "queuelinked.h"
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x){
    Address p = (Address)malloc(sizeof(Node));

    if(p != NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }

    return p;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean isEmpty(Queue q){
    return(ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
int length(Queue q){
    Address p = ADDR_HEAD(q);
    int count = 0;

    if (isEmpty(q)){
        return 0;
    }else{
        while(p != NULL){
            count++;
            p = NEXT(p);
        }
    }

    return count;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateQueue(Queue *q){
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
void DisplayQueue(Queue q){
    Address p = ADDR_HEAD(q);
    printf("[");
    for(int i = 0; i < length(q); i++){
        if (p == ADDR_TAIL(q)){
            printf("%d", INFO(p));
        } else{
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x){
    Address p;

    p = newNode(x);
    if (p != NULL){
        if (isEmpty(*q)){
            ADDR_HEAD(*q) = p;
        } else{
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
void dequeue(Queue *q, ElType *x){
    Address p;

    *x = HEAD(*q);
    p = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));

    if(ADDR_HEAD(*q) == NULL){
        ADDR_TAIL(*q) = NULL;
    }

    free(p);
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
