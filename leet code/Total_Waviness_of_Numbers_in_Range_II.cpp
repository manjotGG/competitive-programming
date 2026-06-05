#include <iostream>

using namespace std;
class Solution {
public:
    struct State {
        long long cnt;
        long long wav;
    };

    string s;
    State dp[20][2][3][11][11];
    bool vis[20][2][3][11][11];

    State dfs(int pos, int tight, int started, int prev2, int prev1) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][started][prev2][prev1]) {
            return dp[pos][tight][started][prev2][prev1];
        }

        vis[pos][tight][started][prev2][prev1] = true;

        State res = {0, 0};

        int lim = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= lim; d++) {
            int ntight = tight && (d == lim);

            if (started == 0) {
                if (d == 0) {
                    State nxt = dfs(pos + 1, ntight, 0, 10, 10);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                } else {
                    State nxt = dfs(pos + 1, ntight, 1, 10, d);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                }
            }
            else if (started == 1) {
                State nxt = dfs(pos + 1, ntight, 2, prev1, d);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else {
                int add = 0;

                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d)) {
                    add = 1;
                }

                State nxt = dfs(pos + 1, ntight, 2, prev1, d);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + nxt.cnt * add;
            }
        }

        return dp[pos][tight][started][prev2][prev1] = res;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, 10, 10).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};