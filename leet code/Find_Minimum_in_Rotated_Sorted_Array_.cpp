#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Minimum is in right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Minimum is in left half including mid
            else if (nums[mid] < nums[high]) {
                high = mid;
            }
            // Duplicates case
            else {
                high--;
            }
        }

        return nums[low];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5};
    cout << "Minimum element: " << sol.findMin(nums1) << endl;

    vector<int> nums2 = {2, 2, 2, 0, 1};
    cout << "Minimum element: " << sol.findMin(nums2) << endl;

    vector<int> nums3 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum element: " << sol.findMin(nums3) << endl;

    return 0;
}