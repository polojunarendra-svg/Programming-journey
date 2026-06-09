#include<stdio.h>
int  main(void) {
    // to slove the given string problem first we need to understand the basic
    // in c we dont String class like in java we only have the charecter so with the help of that we need to create
    // in c we can declare the String in 2 ways and they are by help of char <nameofthecharecter>[] = "string"
    // and another method or way is a s a pointer eg:- char *pparagraph = "String"
    // and to find the length of the string in the c we will be using the sizeof("String")
    /*
     * in c we will be getting the addres of the value which is strored in the memory
     * if we have declared int a = 10
     * we willl be having to ways to get the 10 value or to acces it and thwy
     * -> normallly with the variable a as printf("%d",a);
     * ->Another way is to get the value is to by address of 10
    * int a =10;
       printf("%d",&a);
       i got the output for this 450886044 in my system if we change the system it will definatly changes
     */
    /*
     * and while we create a charecter string in the c only furst addres is strored and for the sec onf=d charecter it will be incremented by
    eg:-char paragraph [] = "Bold hit an bat";
        printf("%p",paragraph[0]);
         i got the output or addres as 0000000000000042 it may changes based on the system and if we try to get the addres of the next charter then we will be getting the incremented value based on the datatype
         eg:- char as 1 bit
         now let us print the addres of the entire string in the system
    char paragraph [] = "Bold hit an bat";
    int j=0;
    while (j<sizeof(paragraph)) {
        printf("%p\n",paragraph[j]);
        j++;
    }

    * 0000000000000042
      000000000000006f
      000000000000006c
      0000000000000064
      0000000000000020
      0000000000000068
      0000000000000069
      0000000000000074
      0000000000000020
      0000000000000061
      000000000000006e
      0000000000000020
      0000000000000062
      0000000000000061
      0000000000000074
       0000000000000000
       if we want the values of the String then we just have to replace the %p with % c
       now let us print sizeof the string in c
    eg:-  char paragraph[] = "Bold hit an bat";
    int a = sizeof(paragraph);
    printf("%d\n",a); and the output is 16
    if we count the number charecters which are present in the paragraph then we will be getting the 16 instead pf 15 because when we calculate the paragraph by default the c we allocate an empty space in the string
    thats the resaon we will be getting the 16  instead of the 15

    Now let us print the individual of the given paragraph
   ---------------------------------------code---------------------------------
    char paragraph [] = "Bold hit an bat";
    int j =0;
    while (j<sizeof(paragraph)-1) {
        if (paragraph[j] == ' ') {
            printf("\n");
            j++;
            continue;
        }
        printf("%c",paragraph[j]);
        j++;
    }
    -----------------------------------ouput--------------------------------------
    Bold
     hit
    an
    bat
     */
    char paragraph [] = "Bold hit an bat";
    char word[100] ="";
    int j =0,i=0;
    int start = 0;
    char temp[10]=" " ;
    while (j<sizeof(paragraph)-1) {
        if (paragraph[j] == ' ') {
            word[start]=temp[i];
            start++;
            temp[i]= 32;
            printf("\n");
            j++;

            continue;
        }
         temp[i]=paragraph[j];
          i++;

        //printf("%c",paragraph[j]);
        j++;
    }
    for (int i =0;i<sizeof(word)-1;i++) {
        printf("%c",word[i]);
    }





}

