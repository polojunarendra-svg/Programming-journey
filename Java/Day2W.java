package Daywise;


public class Day2W {
    public static void main(String[] args){
        String paragraph = "Bob hit a ball Bob hit a ball";
        char [][]words= new char[10][100];
        int wordcount=0;
        for(int i=0,j=0,index=0;i<paragraph.length();i++){
            while(paragraph.charAt(i)!=32&& i<paragraph.length()-1){
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
          for(int j=0;words[i][j]!='\0';j++) {
              System.out.print(words[i][j]);
          }
          System.out.println();
        }
    }
}
