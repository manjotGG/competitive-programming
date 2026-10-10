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
typedef long long ll;
typedef pair<ll, ll> pll;   



bool feasible(const vector<pll>& init, ll n, ll k, ll s) {
    priority_queue<pll> pq(less<pll>(), init);  
    vector<pll> st;                              
    ll used = 0, c = 0;
    while (!pq.empty() && pq.top().first > k) {
        ll v = pq.top().first, m = 0;
        while (!pq.empty() && pq.top().first == v) { m += pq.top().second; pq.pop(); }
        st.push_back(make_pair(v, m));
        c += m;
        ll need = c - max((ll)0, n + 2 * s + k - v);
        while (need > 0) {
            if (used >= s) return false;
            ll x = st.back().first;
            if (x / 2 >= v) return false;
            ll t = min(need, min(st.back().second, s - used));
            st.back().second -= t;
            if (st.back().second == 0) st.pop_back();
            pq.push(make_pair(x / 2, 2 * t));
            c -= t; used += t; need -= t;
        }
    }
   
    while (!pq.empty()) {
        ll v = pq.top().first, m = 0;
        while (!pq.empty() && pq.top().first == v) { m += pq.top().second; pq.pop(); }
        st.push_back(make_pair(v, m));
    }
  
    ll r = s - used;
    while (r > 0 && !st.empty()) {
        ll x = st.back().first, m = st.back().second;
        if (x == 0) { st.back().second += r; r = 0; break; }
        ll t = min(r, m);
        st.back().second -= t;
        if (st.back().second == 0) st.pop_back();
        st.push_back(make_pair(x / 2, 2 * t));
        r -= t;
    }
    ll idx = 0;
    for (int i = (int)st.size() - 1; i >= 0; i--) {   // ascending
        if (st[i].first > k + s + idx) return false;
        idx += st[i].second;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<pll> init;
        for (int i = 0; i < n; i++) {
            ll x = a[i];
            if (!init.empty() && init.back().first == x) init.back().second++;
            else init.push_back(make_pair(x, (ll)1));
        }
        ll lo = 0, hi = 1;
        while (!feasible(init, n, k, hi)) { lo = hi + 1; hi *= 2; }
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (feasible(init, n, k, mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << n + 2 * lo << '\n';
    }
    return 0;
}