//
// Created by poloj on 27-10-2026.
//
#include<stdio.h>
int main(void) {
    int nums[]={1,1,1};
    int k =2;
    int left=0;;
    int right=1;
    int sum=0;
    int count=0;
    while (left<right) {
        sum=sum+nums[right];
        if (sum==k) {
            count=count+1;
            sum=0;
        }
        else if(sum<k) {
            right=right+1;
        }
        else {
            left=left+1;
        }
    }
    printf("%d",count);
}