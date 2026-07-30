//
// Created by poloj on 28-07-2026.
//
#include<string.h>
#include<stdio.h>
int main(void) {
    char string[10]="eceba";
    int k=2;
    char unique[10]="";
    for (int i =0;i<strlen(string);i++) {
        for(int j=i;j<strlen(string);j++) {
            if (unique[i]==string[j]) {
                break;
            }
            if(string[i]!=string[j]) {
                unique[i]=string[i];
            }
        }
    }
    printf("%s",unique);
    return 0;
}
