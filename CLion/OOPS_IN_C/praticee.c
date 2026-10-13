// You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// You can return the answer in any order.
//
//
//
// Example 1:
//
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:
//
// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:
//
// Input: nums = [3,3], target = 6
// Output: [0,1]
//
//
// Constraints:
//
// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
// =============================brute force approach ===============================
// #include<stdio.h>
// int main(void) {
//     int nums[]={3,2,4};
//     int target =6;
//     int sum;
//     int ans[2];
//     int n = sizeof(nums[0]);
//     for (int i =0;i<n;i++) {
//         for (int j =i+1;j<n;j++) {
//             sum = nums[i] + nums[j];
//             if (sum == target) {
//                 ans[0]=i;
//                 ans[1]=j;
//             }
//         }
//     }
//     printf("%d\n",n);
//     printf("[");
//     for (int i =0;i<2;i++) {
//         printf("%d,",ans[i]);
//     }
//     printf("]\n");
//     // we have used the 2 for loops such that the time complexity will be O(n^2)
//     // we cant consider this sloution
//     return 0;
// } O(n) or O(1)
// ==============================Two pointers ================================================
#include<stdio.h>
int main(void) {
    int nums[]={2,7,11,15};
    int target=9;
    int sum;
    int ans[2];
    int n =sizeof(nums[0]);
    int left=0;
    int right=n;
    while(left<right) {
        sum=nums[left]+nums[right];
        if (sum==target) {
            ans[0]=left;
            ans[1]=right;
            break;
        }
        if (sum<target) {
            left++;
        }
        if (sum>target) {
            right--;
        }
    }
    // first we will be stroing the address as  as left as nums[0] which is 2 and in right we will be storing the nums[n] value which is 15
    // in each step it will travse throught theach ele
    // left = 2 right = 15 sum = 17 which not eqaul to target
    // right = n-1 whish is 4-1 = 3 so right will be storing the nums[2] value which is 11
    // now left value will be 2 and right = 11 then sum = 13 which is wrong again
    // so the process will repaet again and the right pointer will be decreaed so the right pointer will be 3-1 which is 2
    // then left = 0, right = nums[1] = which is 7
    // left=2. right = 7 and sum = 9 and the condition stis fyed so ence we have did the problem in the two pointer way
    printf("[");
    for (int i=0;i<2;i++) {
        printf("%d,",ans[i]);
    }
    printf("]\n");
    return 0;
}
