#include <vector>
using namespace std;
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool allEven = true;
        int mn = nums1[0];

        for (int x : nums1) {
            if (x % 2 == 1)
                allEven = false;

            mn = min(mn, x);
        }

        return allEven || (mn % 2 == 1);
    }
};