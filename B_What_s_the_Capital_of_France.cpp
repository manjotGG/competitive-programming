#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <set>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cstring>
using namespace std;

int bestOR(int mask, int L, int R) {
    int memo[31][2][2];
    memset(memo, -1, sizeof(memo));

    function<int(int, int, int)> dp =
        [&](int bit, int tightL, int tightR) -> int {
            if (bit < 0) return 0;

            int &res = memo[bit][tightL][tightR];
            if (res != -1) return res;

            res = 0;
            int lb = (L >> bit) & 1;
            int rb = (R >> bit) & 1;
            int mb = (mask >> bit) & 1;

            for (int b = 0; b <= 1; b++) {
                if (tightL && b < lb) continue;
                if (tightR && b > rb) continue;

                int ntL = tightL && (b == lb);
                int ntR = tightR && (b == rb);

                int value = ((mb | b) << bit)
                          + dp(bit - 1, ntL, ntR);

                res = max(res, value);
            }

            return res;
        };

    return dp(30, 1, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> pref(n + 1, 0), suff(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] | a[i];

        for (int i = n - 1; i >= 0; i--)
            suff[i] = suff[i + 1] | a[i];

        int ans = pref[n];

        for (int i = 0; i < n; i++) {
            int mask = pref[i] | suff[i + 1];

            if (i > 0 && a[i] < a[i - 1]) {
                ans = max(ans, bestOR(mask, a[i], a[i - 1]));
            }

            if (i + 1 < n && a[i] < a[i + 1]) {
                ans = max(ans, bestOR(mask, a[i], a[i + 1]));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
