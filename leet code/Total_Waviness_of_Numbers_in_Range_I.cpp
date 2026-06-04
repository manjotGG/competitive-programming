#include <iostream>

using namespace std;
class Solution {
public:
    struct Node {
        long long ways;
        long long waviness;
    };

    string s;
    Node dp[11][2][3][11][11];
    bool vis[11][2][3][11][11];

    Node dfs(int pos, int tight, int lenState, int prev2, int prev1) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][lenState][prev2][prev1]) {
            return dp[pos][tight][lenState][prev2][prev1];
        }

        vis[pos][tight][lenState][prev2][prev1] = true;

        Node res = {0, 0};

        int limit = tight ? (s[pos] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);

            if (lenState == 0) {
                if (d == 0) {
                    Node nxt = dfs(pos + 1, ntight, 0, 10, 10);
                    res.ways += nxt.ways;
                    res.waviness += nxt.waviness;
                } else {
                    Node nxt = dfs(pos + 1, ntight, 1, 10, d);
                    res.ways += nxt.ways;
                    res.waviness += nxt.waviness;
                }
            }
            else if (lenState == 1) {
                Node nxt = dfs(pos + 1, ntight, 2, prev1, d);
                res.ways += nxt.ways;
                res.waviness += nxt.waviness;
            }
            else {
                int add = 0;

                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d)) {
                    add = 1;
                }

                Node nxt = dfs(pos + 1, ntight, 2, prev1, d);

                res.ways += nxt.ways;
                res.waviness += nxt.waviness + nxt.ways * add;
            }
        }

        return dp[pos][tight][lenState][prev2][prev1] = res;
    }

    long long solve(long long n) {
        if (n <= 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 10, 10).waviness;
    }

    int totalWaviness(int num1, int num2) {
        return (int)(solve(num2) - solve((long long)num1 - 1));
    }
};