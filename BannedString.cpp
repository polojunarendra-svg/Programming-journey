#include <stdio.h>
//#include <string.h>
// #include <string.h>
int strlen(char* str) {
    int count = 0;
    for (int i = 0; str[i] !='\0' ; ++i) {
        count = count + 1;
    }
    return count;
}
int strcmp(char source[],char destination[]){
        // printf("%s\n",destunation);
        //printf("%d\n",strlen(source));
        //printf("%d\n",strlen(destination));

    if (strlen(source)==strlen(destination)) {
        for (int i = 0; i < strlen(source); ++i) {
            if (source[i]!=destination[i]) {
                return 0;
            }
        }
        return 1;

    }
    else {
        return 0;
    }

}
int main(void) {
    setbuf(stdout,0);
    char paragraph[100] = "Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball Bob hit a ball";
    //printf("%d",sizeof(paragraph));
    //printf("%s",paragraph);
    char words[100][10];
    int wcount = 0;
    for (int i = 0,index = 0, j = 0 ; i<sizeof(paragraph)-1;i++) {
        //printf("%c\n",paragraph[i]);
        while (paragraph[i] != ' ' && i <sizeof(paragraph)-1) {
            words[index][j] = paragraph[i];
            i=i+1;
            j= j+1;
        }
        wcount = wcount+1;
        words[index][j] = '\0';
        index = index+1;
        j=0;
    }
    printf("word count = %d\n",wcount);
    for (int i= 0 ; i<wcount;i++) {
        int j = 0;
        while (words[i][j]!='\0') {
            printf("%c",words[i][j]);
            j++;
        }
        printf("\n");
        // printf("%s",words[i]);
        // printf("\n");
    }

    //frequency
    struct wordfrequency {
        char word[10];
        int frequency;
    };
    struct wordfrequency listofword[100];

    printf("======word finding========\n");
    char word[10] = {"ball"};
    printf("%s\n",word);

    for (int  i = 0; i<= wcount;i++) {
        //printf("%s\n",words[i]);
        if (strcmp(word,words[i]) != 0) {
            printf("matched at index %d \n",i);
        }
    }

    // if (-105) {
    //     printf("hi");
    // }
















    return 0;
}