#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10007

typedef struct {
    int key;
    int value;
    int used;
} HashEntry;

int hash(int key) {
    int index = key % TABLE_SIZE;
    if (index < 0) {
        index += TABLE_SIZE;
    }
    return index;
}

void insert(HashEntry table[], int key, int value) {
    int index = hash(key);
    while (table[index].used) {
        index = (index + 1) % TABLE_SIZE;
    }
    table[index].key = key;
    table[index].value = value;
    table[index].used = 1;
}

int find(HashEntry table[], int key) {
    int index = hash(key);
    while (table[index].used) {
        if (table[index].key == key) {
            return table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashEntry* table = (HashEntry*)calloc(TABLE_SIZE, sizeof(HashEntry));

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        int complementIndex = find(table, complement);
        if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            free(table); // Clean up memory
            return result;
        }

        insert(table, nums[i], i);
    }

    free(table);
    return result;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (returnSize == 2) {
        printf("Indices found: [%d, %d]\n", result[0], result[1]);
        printf("Values: %d + %d = %d\n", nums[result[0]], nums[result[1]], target);
        free(result);
    } else {
        printf("No two sum solution found.\n");
    }

    return 0;
}