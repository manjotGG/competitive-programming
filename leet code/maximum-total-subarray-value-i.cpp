#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        return 1LL * k * (mx - mn);
    }
};