#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Minimum right side me hai
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Minimum left side me hai including mid
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};

int main() {
    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "Minimum element is: " << obj.findMin(nums);

    return 0;
}