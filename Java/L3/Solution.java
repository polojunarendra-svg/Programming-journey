package Daywise.L3;

import java.net.SocketOption;

class Solution {
    public int longestOnes(int[] nums, int k) {
        int left=0;
        int zerocount =0;
        int maxlength = 0;
        for(int right =0;right<nums.length;right++){
            if(nums[right]==0){
                zerocount++;
            }
            while(zerocount>k){
                if(nums[left]==0){
                    zerocount--;
                }
                left++;
            }
            maxlength = Math.max(maxlength,right-left+1);
        }
        return maxlength;
    }
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int count =0;
        int left=0,right=0;
        for(right=0;right<nums.length;right++){
            int prod=1;
            prod*=nums[right];
            if(prod>k) left++;
            if (prod<k) count++;
        }
        return count;
    }
    public static void main(String[] args){
        Solution sl = new Solution();
//        int nums[] = {1,1,1,0,0,0,1,1,1,1,0};
//        int k = 2;
//        int ans = sl.longestOnes(nums,k);
//        System.out.println(ans);
        int nums[]={10,5,2,6};
        int  k = 100;
        int ans = sl.numSubarrayProductLessThanK(nums,k);
        System.out.println(ans);
    }

}
