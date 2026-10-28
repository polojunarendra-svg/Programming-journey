//
// Created by poloj on 27-10-2026.
//
#include<stdio.h>
int main(void) {
    int nums[]={0, 1, 0, 3, 12};
    for (int i =0;i<sizeof(nums)/sizeof(int);i++) {
        for (int j =0;j<sizeof(nums)/sizeof(int);j++) {
            if (nums[j]==0) {
               int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
    }printf("[");
    for (int i =0;i<sizeof(nums)/sizeof(int);i++) {
        if (i==sizeof(nums)/sizeof(int)-1) {
            printf("%d",nums[i]);
        }else {
            printf("%d,",nums[i]);
        }
    }
    printf("]\n");
}