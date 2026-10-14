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
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> pref(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            pref[i] = (pref[i - 1] + x) % k;
        }

        vector<long long> freq(k, 0);
        long long ans = 0;

        for (int r = 0; r <= n; r++) {
            int l = r - k - 1;

            if (l >= 0) {
                freq[pref[l]]++;
            }

            ans += freq[pref[r]];
        }

        cout << ans << '\n';
    }

    return 0;
}