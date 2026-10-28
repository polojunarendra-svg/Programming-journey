#include <stdio.h>

int main(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int n = sizeof(nums) / sizeof(nums[0]);
    int temp[7];

    k = k % n;

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }

    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
        printf("%d ", nums[i]);
    }

    return 0;
}