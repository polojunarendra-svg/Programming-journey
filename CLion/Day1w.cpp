#include<stdio.h>
int main(void) {
    char paragraph[]="Bold hit an hat";
    int j=0,i=0;
    char word[30];
    char temp[10];
    int start=0;
    while (j<sizeof(paragraph)-1) {
        if (paragraph[j]==32) {
            word[start]=temp[i];
           // printf("\n");
            temp[i]=32;
            j++;
            continue;
        }
        //printf("%c",paragraph[j]);
        temp[i]=paragraph[j];
        i++;
        j++;
    }
    for (int i =0;i<sizeof(word);i++) {
        printf("%c",word[i]);
    }
}
