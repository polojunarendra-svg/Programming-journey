//
// Created by poloj on 17-08-2026.
//
#include <cstring>
#include <set>
#include<stdio.h>
#define MAX 100
struct Set{
    int data[MAX];
    int size;
};
void add(Set* s,int data) {
    for (int i=0;i<s->size;i++) {
        if (s->data[i]==data) {
            return;
        }
    }
    if (data >=0 &&data <=100) {
        s->data[s->size]=data;
        s->size++;
    }
    else {
        printf("The set is full");
    }
}
void print(Set* s) {
    printf("\n{");
    for (int i=0;i<s->size;i++) {
        printf("%d,",s->data[i]);
    }
    printf("}");
}
void remove(Set* s,int data) {
    for (int i=0;i<s->size;i++) {
        if (s->data[i]==data) {
            for (int j = i; j < s->size - 1; j++) {
                s->data[j] = s->data[j + 1];
            }
            s->size--;

            return;
        }
    }
}
bool contains(Set* s,int data) {
    for (int i=0;i<s->size;i++) {
        if (s->data[i]==data) {
            return true;
        }
    }
    return false;
}
void Union(Set* s1, Set* s2) {
   for (int i = 0; i < s1->size; i++) {
       if (contains(s1,s2->data[i])) {
           continue;
       }else {
           s1=s1+1;
           s1->data[i]=s2->data[i];
       }
   }
}


int main(void) {
    // int temp;
    // char state[10]="";
    // while (strcmp(state,"end")) {
    //     printf("Enter the value to the list:");
    //     scanf("%d",&temp);
    //     printf("Cntinue or not :");
    //     scanf("%9s",state);
    //     if (strcmp(state,"end")==0) {
    //         break;
    //     }
    //     add(&s,temp);
    //     remove(&s,3);
    //     print(&s);
    // }

    struct Set s = {
            .data = {1, 2, 3, 4, 5},
            .size = 5
    };
    struct Set b ={
        .data = {6, 7,8,9,10},
        .size = 5
    };

        printf("Original set: ");
        print(&s);

        remove(&s, 3);

        printf("\nAfter removing 3: ");
        print(&s);

        if (contains(&s, 4)) {
            printf("\n4 is present");
        } else {
            printf("\n4 is not present");
        }
    Union(&s, &b);
    print(&s);




    return 0;
}

