//
// Created by poloj on 27-10-2026.
// //
// #include<stdio.h>
// int main(void) {
//     int nums[]={1,2,3,4};
//     int ans [sizeof(nums)/sizeof(nums[0])];
//     for (int i=0;i<sizeof(nums[0]);i++) {
//         int product=1;
//         for (int j=0;j<sizeof(nums[0]);j++) {
//             if (nums[i]!=nums[j]) {
//                 product=product*nums[j];
//             }
//             ans[i]=product;
//         }
//     }
//     printf("[");
//     for (int i=0;i<sizeof(nums[0]);i++) {
//         if (i==sizeof(nums)/sizeof(nums[0])-1) {
//             printf("%d",ans[i]);
//         }else {
//             printf("%d,",ans[i]);
//         }
//     }
//     printf("]\n");
// }
#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int res[n];
    res[0]=1;
    for(int i=1;i<n;i++){
        res[i]=res[i-1]*nums[i-1];
    }
    int suffix=1;
    for(int i=n-1;i>=0;i--){
        res[i]=res[i]*suffix;
        suffix=suffix*nums[i];
    }
    printf("[");
    for(int i=0;i<n;i++){
        if(i==n-1){
            printf("%d", res[i]);
        }else{
            printf("%d,", res[i]);
        }
    }
    printf("]\n");

    return 0;
}