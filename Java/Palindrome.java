package Daywise;

public class Palindrome {
    public static void main(String[] args){
        String number = "4554";
        int count=0;
        int left=0;
        int n = number.length();
        int right=n-1;
        while(left<right){
            if(number.charAt(left)==number.charAt(right)){
                count=count+1;
            }
            left=left+1;
            right=right-1;
        }
        if(number.length()/2==count){
            System.out.print("Is a palindrome");
        }else {
            System.out.println("Is not a palindrome");
        }
    }
}
