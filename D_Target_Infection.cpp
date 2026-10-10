#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

using ll = long long;

const ll LIM = 1000000000000000000LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll m, k;
        cin >> n >> m >> k;

        map<ll, ll> events;
        events[1] = 0;
        events[LIM + 1] = 0;

        ll initial = 0;

        auto addRange = [&](ll l, ll r, ll v) {
            l = max(l, 1LL);
            r = min(r, LIM);

            if (l > r) return;

            events[l] += v;
            events[r + 1] -= v;
        };

        for (int i = 0; i < n; i++) {
            ll l, r;
            cin >> l >> r;

            ll L = max(l, 1LL);
            ll R = min(r, m);

            if (L <= R)
                initial += R - L + 1;

            addRange(l - m, r - m, 1);
            addRange(l, r, -1);
        }

        ll pos = 1;
        ll cur = initial;
        ll slope = events[1];
        ll ans = -1;

        auto it = events.upper_bound(1);

        while (it != events.end()) {
            ll x = it->first;
            ll right = min(x, LIM);
            ll len = right - pos;

            if (slope == 0) {
                if (cur == k) {
                    ans = pos;
                    break;
                }
            } else {
                ll d = k - cur;

                if (d % slope == 0) {
                    ll step = d / slope;

                    if (step >= 0 && step <= len) {
                        ans = pos + step;
                        break;
                    }
                }
            }

            if (x > LIM)
                break;

            cur += slope * (x - pos);
            pos = x;
            slope += it->second;
            ++it;
        }

        cout << ans << '\n';
    }

    return 0;
}