#include <algorithm>
#include <stdio.h>
#include<ctype.h>
struct wordfrequency {
    char word[15];
    int frequency;
};
int strlen(char* str) {
    int count = 0;
    for (int i = 0; str[i] !='\0' ; ++i) {
        count = count + 1;
    }
    return count;
}
int strcmp(char *source,char *destination){
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
void strcpy(char *destination,char *source) {
    //printf("\n%s\n",destination);
    // printf("%s\n",source);
    int j = 0;
    while (source[j]!='\0') {
        destination[j]=source[j];
        j++;
    }
    destination[j]='\0';

}
char* tolower(char *str) {
    char *strat = str;
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            //162 fails
            //*str-='A'+'a'
            //*str+=97-65;
            *str = *str+32;
        }
        str=str+1;
    }
    return strat;
}
int main(void) {
    setbuf(stdout,0);
    char paragraph[1000] = "BOB HIT A BALL BOB HIT A BALL BOB HIT A BALL BOB HIT A BALL BOB HIT A BALL BOB HIT A BALL BOB HIT A BALL BOB HIT A BALL BOB HIT A BALL BOB HIT A BALL";

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


    printf("======word finding========\n");
    char word[10] = {"a"};
    printf("%s\n",word);

    for (int  i = 0; i< wcount;i++) {
        //printf("%s\n",words[i]);
        if (strcmp(word,words[i]) != 0) {
            printf("matched at index %d \n",i);
        }
    }

    // if (-105) {
    //     printf("hi");
    // }
    //frequency
    printf("%s\n",words[1]);

    struct wordfrequency worddictionary[100];

    for (int i = 0; i < wcount; ++i) {
        strcpy(worddictionary[i].word , words[i]);
        worddictionary[i].frequency = 0;

    }

    // for (int i = 0; i < wcount; ++i) {
    //     printf("%s\t ",worddictionary[i].word);
    //     printf("%d \n",worddictionary[i].frequency);
    //
    // }
    for (int i = 0; i < wcount; ++i) {
        for (int j = 0;j< wcount ; ++j) {
            if (strcmp(worddictionary[i].word,worddictionary[j].word)) {
                worddictionary[i].frequency +=1;
            }
        }
    }
    for (int i = 0; i < wcount; ++i) {
        char *printedwords[10];
        int flag = 0;
        printedwords[i] = worddictionary[i].word;
       // if () {
            printf("%s\t ",worddictionary[i].word);
            printf("%d \n",worddictionary[i].frequency);
        //}


    }
    char unquietwords[100][20];
    for (int i =0,j=0,index=0;i<wcount;i++) {
        while (words[i][j]!='\0') {
            unquietwords[index][j] = words[i][j];
            j++;
        }
        unquietwords[index][j] = '\0';
        index = index+1;
        j=0;
      //  i++;

    }
    // for (int i =0;i<wcount;i++) {
    //     for (int j = 0;j<wcount;j++) {
    //         printf("%c",unquietwords[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("====================\n");
    char uniquewords[100][50];
    int wordsfrequency[100];
    int index1=0,index11=0,index2=0;
    int maxcount[10];
    int indexmaxcount=0;
    char bannedword[10]="";
    for (int i=0;i<wcount;i++) {
        int found=0;

        for (int j=0;j<i;j++) {
            if (strcmp(unquietwords[i],unquietwords[j])) {
                found=1;
                break;
            }
        }
        if (found==0) {
            int count=0;
            for (int k=0;k<wcount;k++) {
                if (strcmp(words[i],words[k])) {
                    count=count+1;
                }
            }

           if (!strcmp(words[i],bannedword)) {
            strcpy( uniquewords[index1],words[i]);
                wordsfrequency[index2]=count;
               index1=index1+1;
               index2=index2+1;
                printf("%s %d\n",unquietwords[i],count);



            }
        }

    }
    printf("----------\n");
    int maxiummcount=0;
    for (int i = 0; i < index1; i++) {
        printf("%s %d\n", uniquewords[i], wordsfrequency[i]);
    }
    for (int i = 0; i < index1; i++) {
        if (wordsfrequency[i] > wordsfrequency[maxiummcount]) {
          maxiummcount=i;
        }
    }
    printf("+++++++++++++++\n");
   // for (char   = 0; i < index1; i++) {
        printf("%s %d\n", uniquewords[maxiummcount], wordsfrequency[maxiummcount]);
  //  }
    for (int i = 0; i < index1; i++) {
        for (int j = 0; j < index1; j++) {
            char ch = unquietwords[i][j];
            if (ch >= 'A' &&ch <= 'Z') {
                ch = ch +32;
            }
        }
    }
    printf("To lower one----\n");
   char  *w = tolower(uniquewords[maxiummcount]);
    printf("%s %d\n", w, wordsfrequency[maxiummcount]);



    // int a = 10;
    // printf("\n%d\n",a);
    // printf("%p\n",(&a));
    // printf("%d",*(&a));












    return 0;
}