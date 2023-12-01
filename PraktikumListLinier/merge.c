#include <stdio.h>
#include "merge.h"
#include "listlinier.h"
#include "boolean.h"

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
    while(ElAddress != NULL){
        if(idx >= midIdx){
            insertLast(back, INFO(ElAddress));
        }
        else{
            insertLast(front, INFO(ElAddress));
        }
        ElAddress = NEXT(ElAddress);
        idx++;
    }
}

List merge(List a, List b){
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/
    if (a == NULL) {return b;}
    else if (b == NULL) {return a;}
    else {
        List res;
        CreateList(&res);
        if (INFO(a) < INFO(b)){
            insertLast(&res, INFO(a));
            return concat(res, merge(NEXT(a), b));
        }
        else{
            insertLast(&res, INFO(b));
            return concat(res, merge(a, NEXT(b)));
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