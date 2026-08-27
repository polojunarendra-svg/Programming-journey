package Daywise.L3;

public class ProductofArrayExceptSelf {
    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4};
        int n = arr.length;
        int ans[] = new int[n];
        int left = 0;
        int i = 0, product = 1;
        int count = 0;
        while (left < n) {
            if (i == left) {
                i++;
                continue;
            }
            product = product * arr[i];
            i = i + 1;
            count = count + 1;
            if (count == n - 1) {
                System.out.print(product+" ");
                ans[left] = product;
                left = left + 1;
                product = 1;
                count = 0;
                i = 0;
            }

        }
    }
}
