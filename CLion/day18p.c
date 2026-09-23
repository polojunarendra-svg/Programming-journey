#include<stdio.h>
#include <string.h>

// struct student {
//     int roll_no;
//     char name[20];
//     char email[20];
//     int age;
// };
// int main(void) {
//     struct student student;
//     student.roll_no = 578;
//     strcpy(student.name, "Narendra");
//     student.age = 20;
//     strcpy(student.email,"narendra@gmail.com");
//     printf("\n%d\n%d\n%s\n%s", student.roll_no,student.age,student.name,student.email);
//     printf("\n");
//     printf("%p\n%p\n%p\n%p",&student,&student,student.age,student.name);
// /*=========================output======================================
//                      578
//                      20
//                      Narendra
//                      narendra@gmail.com
//                      00000084a35ffb00
//                      00000084a35ffb00
//                      0000000000000014
//                      00000084a35ffb04
// =======================================================================
// */
//}
union student {
    int roll_no;
    char name[20];
    char email[20];
    int age;
};
int main(void) {
    union student student;
    student.roll_no = 578;
    strcpy(student.name, "Narendra");
    student.age = 20;
    strcpy(student.email,"narendra@gmail.com");
    printf("\n%d\n%d\n%s\n%s", student.roll_no,student.age,student.name,student.email);
    printf("\n");
    printf("%p\n%p\n%p\n%p",&student,&student,&student.age,&student.name);
    printf("\n%zu\n",sizeof(student));
    /*
     * ====================================output is ==============================
    * 1701994862
      1701994862
      narendra@gmail.com
      narendra@gmail.com
      0000006adfbff6c0
      0000006adfbff6c0
      0000006adfbff6c0
      0000006adfbff6c0
      20
     */
}