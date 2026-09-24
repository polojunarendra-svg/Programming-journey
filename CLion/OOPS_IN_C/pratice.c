#include<stdio.h>
struct class {
    void(*printdetails)(const char *name[],int age);
};
void printdetails(char name[],int age){
    printf("\nYour in the print details function okk\n");
    printf("\nyour name is %s and your age is %d\n",name,age);
}
int main(void) {
    printf("\nYour in the main method and you have started the exectution of the program 0k\n");
    struct class object;
    object.printdetails=printdetails;
    object.printdetails("Hello World",10);
    printf("\nYour are in the main method ok\n");
}