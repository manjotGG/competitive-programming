#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for (int num : nums) {
            ans = min(ans, digitSum(num));
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {10, 12, 13, 14};
    cout << sol.minElement(nums1) << endl; // 1

    vector<int> nums2 = {1, 2, 3, 4};
    cout << sol.minElement(nums2) << endl; // 1

    vector<int> nums3 = {999, 19, 1991};
    cout << sol.minElement(nums3) << endl; // 10

    return 0;
}