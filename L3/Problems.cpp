//
// Created by poloj on 17-07-2026.
//
#include<stdio.h>
int length(int arr[]);
int TwoSum(int arr[],int target,int ans[]);
void ProductOfArray(int arr[]);
int main(void) {
    int arr[]={2,7,11};
    int target=9;
    int ans[2];
    TwoSum(arr,target,ans);
    printf("%d %d",ans[0],ans[1]);
    //---------------------------------
    //failed one
    // int arr[]={1,2,3,4};
    // ProductOfArray(arr);
    return 0;
}
int length(int arr[]) {
    int count=0;
    while(arr[count]!=0) {
        count=count+1;

    }
    return count;
}
int TwoSum(int arr[],int target,int ans[]) {
    int n =length(arr);
    //printf("%d",n);
    int left=0;
    int right=n-1;
    while (left<right) {

        if (arr[left]+arr[right]==target) {
            ans[0]=left;
            ans[1]=right;
            break;
        }
        else if (arr[left]+arr[right]<target) {
            left=left+1;
        }
        else {
            right=right-1;
        }
    }
    if (ans[0]!=-1) {
        return ans[0],ans[1];
    }
    else {
        return -1;
    }

}
//failed in time complexity
void ProductOfArray(int arr[]){
    int n =length(arr);
    int ans[n-1];
    int left=0;
    int i=0,product=1;
    int count=0;
    while (left<n) {
        if (i==left) {
            i++;
            continue;
        }
        product=product*arr[i];
        i=i+1;
        count=count+1;
        if (count==n-2) {
           printf("%d,",product);
            ans[left]=product;
            left=left+1;
            product=1;
            count=0;
            i=0;
        }

    }
    // for (int i=0;i<n-1;i++) {
    //     printf("%d,",ans[i]);
    // }

}