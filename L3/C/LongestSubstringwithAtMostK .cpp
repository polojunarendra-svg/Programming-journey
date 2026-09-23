
#include<string.h>
#include<stdio.h>
int main(void) {
    char string[10]="eceba";
    int k=2;
    int count=0;
    char ans[]="";
    for (int i =0;i<strlen(string);i++) {

        for (int j=i;j<strlen(string);j++) {
            ans[i]=string[i];
            if (string[i]==string[j]) {
                count=count+1;
            }
            if (count==k) {
                break;
            }
        }
    }
    printf("%s",ans);
    return 0;
}
