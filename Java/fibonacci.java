package Daywise;
import java.util.Scanner;

public class fibonacci {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Number:");
        int n = sc.nextInt();
        int n1=0,n2=1;
        while(n>0){
            int sum = n1+n2;
            System.out.println(sum);
            n1=n2;
            n2=sum;
            n=n-1;

        }
    }
}
