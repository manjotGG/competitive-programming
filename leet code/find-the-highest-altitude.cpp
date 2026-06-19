#include <vector>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0, mx = 0;

        for (int x : gain) {
            cur += x;
            mx = max(mx, cur);
        }

        return mx;
    }
};