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
#include <cstring>
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
    if (l1!=l2) {
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

// char *Adding(char *text) {
//     int len=length(text);
//     char temp[10]="";
//     for( int i=0;i<len;i++) {
//         temp=temp+text[i];
//     }
//     return temp;
// }

int main(void) {
    char List[10][10]={"eat","tea","tan","ate","nat","bat"};
    int n =0,i=0;
    while (List[i][0]!=NULL) {
        i=i+1;
        n=n+1;
    }
    printf("N value is : %d\n",n);
    char ans[n][10];
    char temp[n][10];
    char uniquewords[n][10];
    char RealList[n][10];
    for(int i=0;i<n;i++) {
        Stringcopy(RealList[i],List[i]);
        Sorted(RealList[i]);
    }
    for(int i=0;i<n;i++) {
        printf("%s\n",RealList[i]);
    }
    for(int i=0;i<n;i++) {

            for(int j=0;j<n;j++) {
                if (Stringcompare(uniquewords[i],RealList[i])) {
                    continue;
                }
                temp[i][j]=List[i][j];
                uniquewords[i][j]=RealList[i][j];

            }
            ans[i]=temp[i];
            temp[n][n]={};
        }
        for (int i =0;i<n;i++) {
            printf("%s\n",temp[i]);
        }

}
