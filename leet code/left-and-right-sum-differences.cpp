#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int total = 0;
        for (int x : nums) total += x;

        int leftSum = 0;

        for (int i = 0; i < n; i++) {
            total -= nums[i]; // right sum
            ans[i] = abs(leftSum - total);
            leftSum += nums[i];
        }

        return ans;
    }
};