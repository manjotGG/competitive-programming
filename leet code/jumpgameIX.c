#include <stdio.h>
#include <stdlib.h>

/**
 * Note:
 * The returned array must be malloced,
 * assume caller calls free().
 */

int* maxValue(int* nums, int numsSize, int* returnSize) {

    *returnSize = numsSize;

    int* ans = (int*)malloc(sizeof(int) * numsSize);

    int* suffixMin = (int*)malloc(sizeof(int) * numsSize);

    suffixMin[numsSize - 1] = nums[numsSize - 1];

    // Build suffix minimum array
    for (int i = numsSize - 2; i >= 0; i--) {

        if (nums[i] < suffixMin[i + 1])
            suffixMin[i] = nums[i];
        else
            suffixMin[i] = suffixMin[i + 1];
    }

    int start = 0;
    int currentMax = nums[0];

    for (int i = 0; i < numsSize; i++) {

        if (nums[i] > currentMax)
            currentMax = nums[i];

        // Component break condition
        if (i == numsSize - 1 || currentMax < suffixMin[i + 1]) {

            for (int j = start; j <= i; j++) {
                ans[j] = currentMax;
            }

            start = i + 1;

            if (start < numsSize)
                currentMax = nums[start];
        }
    }

    free(suffixMin);

    return ans;
}

int main() {

    int nums[] = {2, 1, 3};

    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;

    int* ans = maxValue(nums, numsSize, &returnSize);

    printf("Output: ");

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }

    printf("\n");

    free(ans);

    return 0;
}