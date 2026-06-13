package Daywise;

public class Day2 {
    public static void main(String[] args){
        String paragraph = "Bob hit a ball";
        char [][]words = new char [10][10];
        int wordcount=0;
        for(int i=0,j=0,index=0;i<=paragraph.length();i++){
            //I am getting index out of bound exception

            while(paragraph.charAt(i)!=' ' && i<paragraph.length()){
                words[index][j]=paragraph.charAt(i);
                i=i+1;
                j=j+1;
            }
            wordcount=wordcount+1;
            words[index][j]='\0';
            index=index+1;
            j=0;
        }
        for(int i=0;i<wordcount;i++){
            int j=0;
            while(words[i][j]!='\0'){
                System.out.print(words[i][j]);
                j++;
            }
            System.out.println();
        }
    }
}
