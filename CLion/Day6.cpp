// Problem: Group Anagrams
// Given an array of strings, group all the anagrams together.
// Two strings are anagrams if they contain the same characters with the same frequencies.
// Example 1
// Plain text
// Input:
// ["eat","tea","tan","ate","nat","bat"]
//
// Output:
// [
//   ["eat","tea","ate"],
//   ["tan","nat"],
//   ["bat"]
// ]
// Example 2
// Plain text
// Input:
// [""]
//
// Output:
// [
//   [""]
// ]
// Example 3
// Plain text
// Input:
// ["a"]
//
// Output:
// [
//   ["a"]
// ]
// Constraints
// 1 <= n <= 10^4
// 0 <= length of each string <= 100
// Strings contain only lowercase English letters.
// Function Signature (C)
// C
// char*** groupAnagrams(char** strs, int strsSize,
//                       int* returnSize,
//                       int** returnColumnSizes);
// Requirements
// Do not compare every string with every other string (O(n²) is too slow).
// Aim for O(n × k log k) (sorting each word) or O(n × k) (character frequency signature), where k is the maximum string length.
#include <list>
#include<stdio.h>
int length(char* text) {
    int count=0;
    while (text[count]!='\0') {
        count++;
    }
    return count;
}
void Stringcopy(char *destination,char *source) {
   // if (length(source)==length(destination)) {
        int i=0;
        while(source[i]!='\0') {
            destination[i]=source[i];
            i=i+1;
        }
        destination[i]='\0';
   // }
}
void Sorted(char *text) {
    int lne = length(text);
  for( int i=0;i<lne-1;i++) {
      for(int j=i;j<lne;j++) {
          if (text[i]>text[j]) {
              char temp=text[i];
              text[i]=text[j];
              text[j]=temp;
          }
      }

  }
}
int Stringcompare(char *text1,char *text2) {
    int count=0;
    int l1 = length(text1);
    int l2 = length(text2);
    if (l1==l2) {
        for (int i=0;i<l1;i++) {
            if (text1[i]==text2[i]) {
                count=count+1;
            }
        }
    }
    if (count==l1) {
        return 1;
    }
    else {
        return 0;
    }
}

char *Adding(char *s1,char *s2) {

}

int main(void) {
    char List[10][10]={"eat","tea","tan","ate","nat","bat"};
    int n =0;
    while (List[n][0]!='\0') {
        n=n+1;
    }
    char RealList[10][10];
    printf("%d\n",n);
    for (int i=0;i<n;i++){
        Stringcopy(RealList[i],List[i]);
        Sorted(RealList[i]);
        printf("%s\n",RealList[i]);
    }
    int state[n];
    for (int i=0;i<n;i++) {
        state[i]=0;
    }
    printf("///////////\n");
    for (int i=0;i<n;i++) {
        if (state[i]==1) {
            continue;
        }
        printf("[");
        printf("%s,",List[i]);
        state[i]=1;
        for (int j=i+1;j<n;j++) {
            if (Stringcompare(RealList[i],RealList[j])) {
                printf(",%s",List[j]);
                state[j]=1;
            }
        }
        printf("]\n");

    }
    return 0;

}