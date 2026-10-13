
#include <stdio.h>

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int nums[] = {1, 0, 1, 1, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int count = 0;
    int max = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            count = 0;
        } else {
            count = count + 1;
            max = maximum(max, count);
        }
    }

    printf("%d\n", max);

    return 0;
}