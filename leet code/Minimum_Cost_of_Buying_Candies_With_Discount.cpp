#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());   // expensive candies first

        int ans = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) {        // every 3rd candy free
                ans += cost[i];
            }
        }

        return ans;
    }
};