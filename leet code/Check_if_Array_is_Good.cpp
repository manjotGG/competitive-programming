#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());

        // A good array should contain numbers from 1 to n,
        // with n appearing exactly twice.
        if (nums.size() != n + 1)
            return false;

        vector<int> freq(n + 1, 0);

        for (int x : nums) {
            if (x < 1 || x > n)
                return false;

            freq[x]++;
        }

        // Numbers from 1 to n-1 must appear exactly once
        for (int i = 1; i < n; i++) {
            if (freq[i] != 1)
                return false;
        }

        // Number n must appear exactly twice
        return freq[n] == 2;
    }
};