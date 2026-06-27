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
int mystrlen(char str[]){
    int count=0;
    for(int i =0;str[i]!='\0';i++){
        count=count+1;
    }
    return count;
}
// int sizeof(char str[]){
//     int count=0;
//     int i;
//     while(str[i]!='\0'){
//         count=count+1;
//     }
//     return count;
// }
int main(void) {
    char word[10][20]= {"eat","tea","tan","ate","nat","bat"};
    int answer[10];
    for (int i=0;i<10;i++) {
        int len = mystrlen(word[i]);
        int sum=0;
        for (int j=0;j<len;j++) {
            sum =  sum+ word[i][j];
        }
        answer[i]=sum;
        //printf("%s\n",answer[i]);

        //index=index+1;

    }
    for (int i = 0;i<10;i++) {
        printf(" %s->%d\n",word[i],answer[i]);
    }
    int index=0;
    int row=0;
    char result[10][20];
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            if (answer[i]==answer[j]) {
                strcpy(result[index],word[j]);
            }
        }
        index=index+1;

    }

    return 0;

}