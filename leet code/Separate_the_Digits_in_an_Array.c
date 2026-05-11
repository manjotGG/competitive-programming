#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    
    int total = 0;

    // Count total digits
    for(int i = 0; i < numsSize; i++) {
        int temp = nums[i];

        if(temp == 0) {
            total++;
        } 
        else {
            while(temp > 0) {
                total++;
                temp /= 10;
            }
        }
    }

    int* ans = (int*)malloc(total * sizeof(int));
    int idx = 0;

    // Separate digits
    for(int i = 0; i < numsSize; i++) {

        int temp = nums[i];
        int digits[10];
        int k = 0;

        if(temp == 0) {
            ans[idx++] = 0;
        } 
        else {

            // Store digits in reverse
            while(temp > 0) {
                digits[k++] = temp % 10;
                temp /= 10;
            }

            // Add digits in correct order
            for(int j = k - 1; j >= 0; j--) {
                ans[idx++] = digits[j];
            }
        }
    }

    *returnSize = total;
    return ans;
}

int main() {

    int nums[] = {13, 25, 83, 77};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;

    int* result = separateDigits(nums, numsSize, &returnSize);

    printf("Output: [");

    for(int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);

        if(i != returnSize - 1) {
            printf(", ");
        }
    }

    printf("]\n");

    free(result);

    return 0;
}