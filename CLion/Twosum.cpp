//
// Created by poloj on 12-07-2026.
//
// input :- nums = [2,7,11] , target = 9 , output :- [0,1] Hint :-Use hasmap for get better time complexity
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int key;
    int value;
} HashEntry;
HashEntry map[100];
int hash(int key) {
    return key%100;
}
void init_map() {
    for(int i=0;i<100;i++) {
        map[i].key=-1;
        map[i].value=-1;
    }
}
int contains(int key) {
    int index=hash(key);
    return map[index].key !=-1;
}
void add(int key, int value) {
    int index=hash(key);
    map[index].key=key;
    map[index].value=value;
}
int main(void) {
    int nums []={2,7,11};
    int target=9;
    int n = sizeof(nums)/sizeof(nums[0]);
    init_map();
    for(int i=0;i<n;i++) {
        int complement = target - nums[i];
        if (contains(complement)) {
            printf("[%d,%d]\n", map[complement].value, i);
            return 0;
        }
        add(nums[i],i);
    }
    printf("No solution exits");
    return 0;
}