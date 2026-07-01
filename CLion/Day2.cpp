#include<stdio.h>
int main(void) {
    char paragraph[100] = "Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball";
    char words[10][10];
    int wordCount=0;
    for (int i=0,j=0,index=0;i<sizeof(paragraph)-1;i++) {
        while (paragraph[i]!=32 && i<sizeof(paragraph)) {
            words[index][j]=paragraph[i];
            i=i+1;
            j=j+1;
        }
        wordCount=wordCount+1;
        words[index][j]='\0';
        index=index+1;
        j=0;
    }
    for (int i=0;i<wordCount;i++) {
        int j=0;
        while (words[i][j]!='\0') {
            printf("%c",words[i][j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}