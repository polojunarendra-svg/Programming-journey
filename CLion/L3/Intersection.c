#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Helper: Check if number exists in nums2 with count
int findIntersection(int nums1[], int nums2[], int nums1Size, int nums2Size) {
    // Step 1: Count frequencies in nums2
    int count[100] = {0}; // Assuming numbers are small (0-99)
    for (int j = 0; j < nums2Size; j++) {
        count[nums2[j]]++;
    }

    // Step 2: Add matches from nums1 (only add min(count, 1) per number)
    int result[100] = {0}; // Result array (smaller than nums1)
    int resultSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        int num = nums1[i];
        if (count[num] > 0) {
            result[resultSize++] = num;
            count[num]--;
        }
    }

    // Print result (for your example: [2, 2])
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    return resultSize;
}

int main() {
    int nums1[] = {1,  2,  2,  1};
    int nums2[] = {2,  2};
    int nums1Size = 4;
    int nums2Size = 2;

    findIntersection(nums1, nums2, nums1Size, nums2Size);
    return 0;
}