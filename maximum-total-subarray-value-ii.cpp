#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> lg(n + 1);
        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int K = lg[n] + 1;

        vector<vector<int>> mx(K, vector<int>(n));
        vector<vector<int>> mn(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mx[0][i] = nums[i];
            mn[0][i] = nums[i];
        }

        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[j][i] = max(
                    mx[j - 1][i],
                    mx[j - 1][i + (1 << (j - 1))]
                );

                mn[j][i] = min(
                    mn[j - 1][i],
                    mn[j - 1][i + (1 << (j - 1))]
                );
            }
        }

        auto rangeValue = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int p = lg[len];

            int maxi = max(
                mx[p][l],
                mx[p][r - (1 << p) + 1]
            );

            int mini = min(
                mn[p][l],
                mn[p][r - (1 << p) + 1]
            );

            return 1LL * maxi - mini;
        };

        struct Node {
            long long val;
            int l, r;

            bool operator<(const Node& other) const {
                return val < other.val;
            }
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({rangeValue(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto cur = pq.top();
            pq.pop();

            ans += cur.val;   // <-- yahi bug tha

            if (cur.r > cur.l) {
                pq.push({
                    rangeValue(cur.l, cur.r - 1),
                    cur.l,
                    cur.r - 1
                });
            }
        }

        return ans;
    }
};