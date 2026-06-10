package Daywise;

import java.util.ArrayList;

public class Day1W {
    public static void main(String[] args){
        String paragraph = "Bold hit an bat";
        int j=0;
        ArrayList<String> str = new ArrayList<>();
        int start =0;
        while(j<paragraph.length()){
            char ch = paragraph.charAt(j);
            if(ch==32){
                str.add(paragraph.substring(start,j));
                start=j+1;
            }
            j++;

        }
        str.add(paragraph.substring(start));

        System.out.println(str);

    }
}