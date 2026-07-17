//
// Created by poloj on 13-07-2026.
//
#include <cstring>
#include<stdio.h>
int main(void) {
    char number[]={"4554"};
    int count=0;
    int left=0;
    int right=strlen(number)-1;
    while(left<right) {
        if(number[left]==number[right]) {
            count++;
        }
        left++;
        right--;
    }
    if (strlen(number)/2==count) {
        printf("Palindrome");
    }
    else {
        printf("Not Palindrome");
    }
}