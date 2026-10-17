#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <random>
#include <chrono>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() ^ 0x9e3779b97f4a7c15ULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ull> diff(n + 2, 0);
        for (int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            ull h = rng();
            diff[l] ^= h;
            diff[r + 1] ^= h;
        }
        vector<pair<ull, int> > sg(n);
        ull cur = 0;
        for (int i = 1; i <= n; i++) {
            cur ^= diff[i];
            sg[i - 1] = make_pair(cur, i);
        }
        sort(sg.begin(), sg.end());
        // ranges of cut positions + classes (first,last) with size >= 2
        vector<pair<int,int> > ranges;       // [a,b]
        vector<pair<int,int> > cls;          // (first,last)
        for (int i = 0; i < n;) {
            int j = i;
            while (j + 1 < n && sg[j + 1].first == sg[i].first) j++;
            if (j > i) {
                for (int q = i; q < j; q++)
                    ranges.push_back(make_pair(sg[q].second, sg[q + 1].second - 1));
                cls.push_back(make_pair(sg[i].second, sg[j].second));
            }
            i = j + 1;
        }
        if (ranges.empty()) { cout << 0 << '\n'; continue; }

        // R1: smallest possible first point of a minimum stabbing set (greedy from the right)
        vector<pair<int,int> > byA = ranges;
        sort(byA.begin(), byA.end());                     // by a ascending
        int p = 1 << 30, R1 = 0;
        for (int i = (int)byA.size() - 1; i >= 0; i--) {
            if (byA[i].second < p) { p = byA[i].first; R1 = p; }
        }
        // S = {R1} + left-greedy on ranges not containing R1
        vector<pair<int,int> > byB;                       // (b,a)
        for (size_t i = 0; i < ranges.size(); i++) {
            int a = ranges[i].first, b = ranges[i].second;
            if (a <= R1 && R1 <= b) continue;
            byB.push_back(make_pair(b, a));
        }
        sort(byB.begin(), byB.end());
        vector<int> S;
        S.push_back(R1);
        int last = -1;
        for (size_t i = 0; i < byB.size(); i++) {
            if (byB[i].second > last) { last = byB[i].first; S.push_back(last); }
        }
        int H = (int)S.size();
        vector<int> G;
        int h;
        if (H % 2 == 1) {
            G.push_back(0);
            for (int i = 0; i < H; i++) G.push_back(S[i]);
            h = (H + 1) / 2;
        } else {
            bool ok = true;
            int g1 = S[0], gH = S[H - 1];
            for (size_t i = 0; i < cls.size(); i++)
                if (cls[i].first <= g1 && cls[i].second > gH) { ok = false; break; }
            if (ok) {
                G = S;
                h = H / 2;
            } else {
                G.push_back(0);
                for (int i = 0; i < H; i++) G.push_back(S[i]);
                G.push_back(n);
                h = H / 2 + 1;
            }
        }
        cout << h << '\n';
        for (int i = 0; i < h; i++)
            cout << G[i] + 1 << ' ' << G[i + h] << '\n';
    }
    return 0;
}