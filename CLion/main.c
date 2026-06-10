#include <stdio.h>
#include<string.h>

int banned(void) {
   char paragraph [] = "Bold hit an bat";
    int j=0;
    while (j<sizeof(paragraph)-1) {
        if (paragraph[j] == ' ') {
            printf("\n");
            j++;
            continue;
        }
        printf("%c",paragraph[j]);
        j++;
    }

    return 0;
}
 // In normal way
void  print (void) {
    int a =34;
    printf("%d",a);
}
// In offical way useing fputs and fgets
void printSpecial(void) {
    fputs("This is my string\n", stdout);
    char name[20];
    printf("Enter your name: \n");
    fgets(name, sizeof(name), stdin);
    printf("Hello, %s", name);

}
// doubt should ask to sir
void doubt(void) {
    char ch = 'A';
    putchar(ch);
    printf("%d", putchar(ch));
    printf("\n-----------------\n");
    printf("%d", printf("%d", 1234));
    printf("\n--------------------\n");
    // Danger code (Infinite loop) output is 30 40 2
    /*int a = 10, b = 20, c;
    c = scanf("%d %d", &a, &b);
    printf("%d %d %d\n", a, b, c);*/
    // int a, b;
    // scanf("%d", &a);
    // b = getchar();
    // printf("a = %d, b = %d", a, b);
    // printf("---------");
    // int x = 128;
    // printf("\n%d", 1 + x++);
    // printf("%d", x);
    // printf("------------");
    // int i = (1, 2, 3);
    //
    // printf("\n%d", i);
    // printf("---------");
    //
    // int i = 5, j = 10, k = 15;
    // printf("%d ", sizeof(k /= i + j));
    // printf("%d", k);
    // printf("-----------");
    // int a = 0;
    // int b;
    // a = (a == (a == 1));
    // printf("%d", a);

}


void table(int n);

int main(void) {

    return 0;
}


void table(int n) {
    for (int i = 1; i <= 10; i++) {
        printf("%d x%d=%d\n",n,i,n * i);
    }
}




