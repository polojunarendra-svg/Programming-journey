package Daywise;

import java.util.HashMap;

class Problems{
    public static  void main(String[] args){
      Problems p = new Problems();
        int []arr={2,7,11};
        int target =9;
      p.TwoSumHash(arr,target);
//        int [] arr ={1,2,3,4};
//        p.ProductOfArray(arr);
    }
    public static int length(int[] arr){
        int count=0;
       for(int i =0;i!='\0';i++){
           count=count+1;
        }
        return count;
    }
    public static void TwoSum(int[] arr,int target){
        int n = arr.length;
        int left=0;
        int right=n-1;
        int[] ans = new int[2];
        while(left<right){
            if(arr[left]+arr[right]==target){
                ans[0]=left;
                ans[1]=right;
                break;
            }
            else if(arr[left]+arr[right]<target){
                left=left+1;
            }
            else {
                right=right-1;
            }
        }
        if(ans[0]!=-1){
            System.out.print(ans[0]+" "+ans[1]);
        }
        else {
            System.out.print("target is not ffromed by the given values");
        }

    }
    public static void TwoSumHash(int []arr,int target){
        HashMap <Integer,Integer> map =new HashMap<>();
        int isFound = 0;

        for (int i = 0; i < arr.length; i++) {
            int complement = target - arr[i];
            if (map.containsKey(complement)) {
                System.out.print(map.get(complement) + " " + i);
                isFound = 1;
                break;
            }
            map.put(arr[i], i);
        }

        if (isFound == 0) {
            System.out.print("target is not formed by the given values");
        }

    }
    public static void ProductOfArray(int[] arr){
        int n = arr.length;
        int [] ans= new int[n];
        int left=0;
        int product=1,i=0,count=0;
        while(left<n){
            if(i==left){
                i=i+1;
                continue;
            }
            product=product*arr[i];
            i=i+1;
            count=count+1;
            if(count==n-1){
                System.out.print(product+" ");
                ans[left]=product;
                i=0;
                left=left+1;
                count=0;
                product=1;
            }

        }
    }
}
