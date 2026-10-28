//
// Created by poloj on 26-10-2026.
//
#include<stdio.h>
int main(void) {
    int a=14;
    int b=6;
    int abinarray[4];
    int bbinarray[4];
    int i=0;
    while (a>0) {
        int rem = a%2;
        abinarray[i]=rem;
        a=a/2;
        i=i+1;
    }
    i=0;
    while (b>0) {
        int rem = b%2;
        bbinarray[i]=rem;
        b=b/2;
        i=i+1;
    }
    printf("[");
    for (int i=0;i<4;i++) {
        printf("%d,",abinarray[i]);
    }
    printf("]\n[");
    for (int i=0;i<4;i++) {
        printf("%d,",bbinarray[i]);
    }
    printf("]");
    int abin[4];
    int bbin[4];
    int j=0;
    for (int i=3;i>=0;i--) {
        abin[j]=abinarray[i];
        j=j+1;
    }
    j=0;
    for (int i=3;i>=0;i--) {
        bbin[j]=bbinarray[i];
        j=j+1;
    }
    int acount=0;
    int bcount=0;
    for (int i=0;i<4;i++) {
        if (abin[i]==1) {
            acount=acount+1;
        }
    }
    for (int i=0;i<4;i++) {
        if (bbin[i]==1) {
            bcount=bcount+1;
        }
    }
    int result;
    if (acount >= bcount) {
        result = acount * bcount;
        printf("\n%d",result);
    } else {
        result = bcount / acount;
        printf("\n%d",result);
    }

    return 0;
}