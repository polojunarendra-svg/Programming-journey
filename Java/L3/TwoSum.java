package Daywise.L3;
import java.util.HashMap;

public class TwoSum {
    public static void main(String[] args) {

        int[] arr = {2, 7, 11, 12};
        int target = 9;

        HashMap<Integer,Integer> map = new HashMap<>();

        for(int i=0;i<arr.length;i++) {
            int complement=target-arr[i];
            if(map.containsKey(complement)){
                System.out.println(map.get(complement)+" "+i);
                return;
            }
            map.put(arr[i],i);
        }
    }
}