#include <vector>
using namespace std;
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int prefixMax = nums[0];

            for (int j = 1; j <= i; j++) {
                prefixMax = max(prefixMax, nums[j]);
            }

            int suffixMin = nums[i];

            for (int j = i; j < n; j++) {
                suffixMin = min(suffixMin, nums[j]);
            }

            if (prefixMax - suffixMin <= k) {
                return i;
            }
        }

        return -1;
    }
};