#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 1};
    int numsSize = 4;

    int left = 0;
    int right = 1;

    while (left < numsSize - 1) {
        if (nums[left] == nums[right]) {
            printf("true\n");
            return 0;
        }

        right++;

        if (right == numsSize) {
            left++;
            right = left + 1;
        }
    }

    printf("false\n");
    return 0;
}
