public class Day1 {
    public static void main(String args){
        String paragraph = "Bold hit an bat";
        int j=0;
        while(j<paragraph.length()){
            char ch = paragraph.charAt(j);
            if(ch==32){
              System.out.println();
              j++;
              continue;
            }
            System.out.print(ch);
            j++;
        }

    }
}
