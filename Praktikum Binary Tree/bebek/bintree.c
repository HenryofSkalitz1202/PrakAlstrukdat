#include "boolean.h"
#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree)
{
    BinTree p = newTreeNode(root);
    if (p != NULL)
    {
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}

/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi
   berhasil
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */
void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
{
    BinTree temp = newTreeNode(root);

    if (temp != NULL)
    {
        LEFT(temp) = left_tree;
        RIGHT(temp) = right_tree;
    }
    *p = temp;
}

/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL
   Jika alokasi gagal, mengirimkan NULL */
Address newTreeNode(ElType val)
{

    Address p = (Address)malloc(sizeof(TreeNode));

    if (p != NULL)
    {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

/* I.S. p terdefinisi
   F.S. p dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address p */
void deallocTreeNode(Address p)
{
    free(p);
}

/* Mengirimkan true jika p adalah pohon biner yang kosong */
boolean isTreeEmpty(BinTree p)
{
    return p == NULL;
}

/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
boolean isOneElmt(BinTree p)
{
    return !isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL;
}

/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft:
   hanya mempunyai subpohon kiri */
boolean isUnerLeft(BinTree p)
{
    return !isTreeEmpty(p) && RIGHT(p) == NULL && LEFT(p) != NULL;
}

/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright:
   hanya mempunyai subpohon kanan */
boolean isUnerRight(BinTree p)
{
    return !isTreeEmpty(p) && RIGHT(p) != NULL && LEFT(p) == NULL;
}

/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner:
  mempunyai subpohon kiri dan subpohon kanan */
boolean isBinary(BinTree p)
{
    return !isTreeEmpty(p) && RIGHT(p) != NULL && LEFT(p) != NULL;
}

/* ****** Display Tree ***** */
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void printPreorder(BinTree p)
{

    printf("(");
    if (!isTreeEmpty(p))
    {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }

    printf(")");
}

/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void printInorder(BinTree p)
{

    printf("(");
    if (!isTreeEmpty(p))
    {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }

    printf(")");
}

/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void printPostorder(BinTree p)
{

    printf("(");
    if (!isTreeEmpty(p))
    {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }

    printf(")");
}

void helperPrint(BinTree p, int h, int count)
{

    int i;

    if (!isTreeEmpty(p))
    {
        for (i = 0; i < h * count; i++)
        {
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        helperPrint(LEFT(p), h, count + 1);
        helperPrint(RIGHT(p), h, count + 1);
    }
}

/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
void printTree(BinTree p, int h)
{
    helperPrint(p, h, 0);
}

int hitungBebek(BinTree root, int n) {
    int rootmod, res;
    rootmod = ROOT(root) % 10000;
    res = 0;

    if(n == ROOT(root)){
        return rootmod;
    } else{
        if(LEFT(root) != NULL){
            res += (rootmod * hitungBebek(LEFT(root), n - ROOT(root))) % 10000;
        }
        if(RIGHT(root) != NULL){
            res += (rootmod * hitungBebek(RIGHT(root), n - ROOT(root))) % 10000;
        }
        return res;
    }
}
