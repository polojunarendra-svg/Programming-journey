package Daywise.L3;

public class SubarraySumEqualsK {
    public static void main(String[] args){
        int arr[]={1,1,1};
        int target=2;
        int count=0,i=0;
        int n =arr.length;
        int left=0;
        int right=left+1;
        int sum=0;
        while (left<n-1) {
            sum=sum+arr[i];
            if (sum==target) {
                left=left+1;
                count=count+1;
                sum=0;
            }
            else {
                right=right+1;
                i=i+1;
            }
        }
        System.out.println(count);
    }
}
