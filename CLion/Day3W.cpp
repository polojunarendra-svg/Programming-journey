#include <cstring>
#include<stdio.h>
int strlen(char * str) {
    int count=0;
    for (int i =0;str[i]!='\0';i++) {
        count++;
    }
    return count;
}
int strcmp(char *s1, char *s2) {
    if (strlen(s1) == strlen(s2)) {
        for (int i =0;i<strlen(s1);i++) {
            if (s1[i]!=s2[i]) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
void strcpy(char *s1, char *s2) {
    int i=0;
    while (s2[i]!='\0') {
        s1[i]=s2[i];
        i=i+1;
    }
    s1[i]='\0';
}
typedef struct {
    char word[60];
    int frequency;
}wordpair;
typedef struct {
    wordpair items[90];
    int size;
}Dictonary;
Dictonary dict(char words[80][300],int wordcount) {
    Dictonary dict;
    dict.size=0;
    for (int i =0;i<wordcount;i++) {
        int found=0;
        for (int j =0;j<dict.size;j++) {
            if (strcmp(dict.items[j].word,words[i])==1) {
                dict.items[j].frequency++;
                found=1;
                break;
            }
        }
        if (!found) {
            strcpy(dict.items[dict.size].word,words[i]);
            dict.items[dict.size].frequency=1;
            dict.size++;
        }
    }
    return dict;
}
int main(void) {
    char paragraph[150] ="Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball";
    char words[80][300];
    int wordcount=0;
    int frequency=0;
    for (int i=0,j=0,index=0;i<sizeof(paragraph)-1;i++) {
        while (paragraph[i]!=' ' && i<sizeof(paragraph)-1) {
            words[index][j]=paragraph[i];
            i=i+1;
            j++;
        }
        words[index][i]='\0';
        index++;
        j=0;
        wordcount++;
    }
    char word[10]={"ball"};
    for (int i=0;i<wordcount;i++) {
        int j=0;
        while (words[i][j]!='\0') {
            printf("%c",words[i][j]);
            j++;
        }
        printf("\n");
    }
    printf("================================================\n");
    for (int i =0;i<wordcount;i++) {
        if (strcmp(words[i],word)!=0) {
            printf("Match found at the %d:\n",i);
            frequency=frequency+1;
        }
    }
    printf("Frequency of the word %s is %d \n",word,frequency);

}