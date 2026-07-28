//
// Created by poloj on 28-07-2026.
//
#include<stdio.h>

int StringCompare(char *source, char *destination);
int length(char *string);
int contains(char *str, char ch);
void copy(char *source, char *destination);
int main(void) {
    char string[] = "abcabcbb";
    char ans[20] = "";
    char temp[20];
    int maxLen=0;
    for(int i=0;i<length(string);i++)
    {
        int k=0;
        temp[0]='\0';
        for(int j=i;j<length(string);j++)
        {
            if(contains(temp,string[j]))
                break;

            temp[k]=string[j];
            k=k+1;
            temp[k]='\0';

            if(k>maxLen)
            {
                maxLen=k;
                copy(ans, temp);
            }
        }
    }
    printf("%s and wtih the length %d",ans, maxLen);
}
int StringCompare(char *source, char *destination){
    int len=length(source);
    if(len!=length(destination))
        return 0;
    for (int i = 0; i < len; i++)
    {if (source[i] != destination[i])
            return 0;
    }
    return 1;
}
int length(char *string){
    int count=0;
    while(string[count]!='\0')
    {
        count++;
    }
    return count;
}
void copy(char *source, char *destination)
{
    int n=length(destination);
    for(int i=0;i<=n;i++)
        source[i]=destination[i];
}
int contains(char *str, char ch)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]==ch)
            return 1;
        i=i+1;
    }
    return 0;
}
