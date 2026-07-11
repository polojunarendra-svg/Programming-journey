#include<stdio.h>
 int Stringlength(const char *Str){
    int i=0;
    while (Str[i]!='\0') {
        i=i+1;
    }
    return i;
}
int main(void) {
    int count = 0;
    char Number[] = "111111111111111111111111";
    int counsucutivesones=0;
    for (int i =0;i<Stringlength(Number);i++) {
    if (Number[i]=='1') {
        count=count+1;
        if (count==5) {
            counsucutivesones=counsucutivesones+1;
            count=0;
        }
    }
   }
    int freq=0;
    while (counsucutivesones>0) {
        printf("1");
        freq=freq+1;
        if (freq==5) {
            printf("0");
            counsucutivesones=counsucutivesones-1;
            freq=0;
        }
    }
    while (count>0) {
        printf("1");
        count=count-1;
    }
    return 0;
}
