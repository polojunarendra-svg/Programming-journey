//
// Created by poloj on 18-06-2026.
//
#include <stdio.h>
int stringlength(char *str) {
    int count=0;
    for (int i =0;str[i]!='\0';i++) {
        count=count+1;
    }
    return count;
}
int stringCompare(char *destination, char *source) {
    if (stringlength(source)==stringlength(destination)) {
        for (int i =0;i!=stringlength(source);i++) {
            if (destination[i]!=source[i]) {
                return 0;
            }

        }
        return 1;
    }else {
        return 0;
    }
}
void stringcopy(char *destination, char *source) {
    printf("\n%s\n",destination);
    printf("%s\n",source);
}
int main(void) {
    char paragraph[1000] = "Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball";
    char words[100][10];
    int wordcount=0;
    for (int i =0,j=0,index=0;i<stringlength(paragraph);i++) {
        while (paragraph[i]!=32 && i<stringlength(paragraph)) {
            words[index][i]=paragraph[i];
            i++;
            j++;
        }
        wordcount=wordcount+1;
        words[index][i]='\0';
        index++;
        j=0;
    }
    for (int i =0;i<wordcount;i++) {
        int j=0;
        while (words[i][j]!='\0') {
            printf("%c",words[i][j]);
            i++;
            j++;
        }
        printf("\n");
    }
    printf("===========Word finding===========\n");
    char word[10]={"a"};
    printf("%s\n",word);
    for (int i =0;i<wordcount;i++) {
        if (stringCompare(word,words[i])!=0) {
            printf("Matched at Index:%d\n",i);
        }
    }
    printf("\n%s\n",words[1]);
}