#include <stdio.h>
#include <stdlib.h>

int maximumJumps(int* nums, int numsSize, int target) {
    
    int* dp = (int*)malloc(sizeof(int) * numsSize);

    for(int i = 0; i < numsSize; i++) {
        dp[i] = -1;
    }

    dp[0] = 0;

    for(int i = 0; i < numsSize; i++) {

        if(dp[i] == -1) continue;

        for(int j = i + 1; j < numsSize; j++) {

            long long diff = (long long)nums[j] - nums[i];

            if(diff >= -target && diff <= target) {

                if(dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
    }

    int ans = dp[numsSize - 1];

    free(dp);

    return ans;
}