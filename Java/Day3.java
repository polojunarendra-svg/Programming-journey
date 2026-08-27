package Daywise;


public class Day3 {
    public static void main(String[] args){
        String  paragraph = "Bob hit an ball";
        char [][]words = new char[10][50];
        int wordcount=0;
        String word = "Bob";
        for(int i=0,j=0,index=0;i<paragraph.length();i++){
            while(paragraph.charAt(i)!=' '&& i<paragraph.length()){
               words[index][j]=paragraph.charAt(i);
               i=i+1;
               j=j+1;
            }
            words[index][j]='\0';
            index=index+1;
            wordcount=wordcount+1;
            j=0;

        }
        for(int i=0;i<wordcount;i++){
            int j =0;
            while(words[i][j]!='\0'){
                System.out.print(words[i][j]);
                j=j+1;
            }
            System.out.println();
        }
        for(int i =0;i<wordcount;i++){
            String currentWord = "";
            int j=0;
            while(words[i][j]!='\0') {
                currentWord =currentWord+ words[i][j];
                j++;
            }
            if (strcmp(currentWord, word) == 1) {
                System.out.println("Matched at " + i);
            }
        }
    }
   public static  int length(String str){
        int count=0;
        for(int i=0;str.charAt(i)!='\0';i++){
            count=count+1;
        }
        return count;
    }
    public static int strcmp(String str1,String str2){
        System.out.print(length(str1)+""+length(str2));
        if(length(str1)==length(str2)){

           for(int i=0;i<length(str1);i++){
               if(str1.charAt(i)!=str2.charAt(i)){
                   return 0;
               }
            }
           return 1;
        }
        return 0;
    }
}
