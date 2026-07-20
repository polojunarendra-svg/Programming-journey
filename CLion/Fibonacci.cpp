//
// Created by poloj on 13-07-2026.
//
#include<stdio.h>
int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int n1=0,n2=1;
    while (n>0) {
        int sum=n1+n2;
        printf("%d\n",sum);
        n1=n2;
        n2=sum;
        n=n-1;
    }
}