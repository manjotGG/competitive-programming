#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <set>  
using namespace std;

class Solution {
public:
    struct SegTree {
        int n;
        vector<int> st;

        SegTree(int n) : n(n), st(4 * n + 5, 0) {}

        void update(int idx, int val, int node, int l, int r) {
            if (l == r) {
                st[node] = val;
                return;
            }

            int m = (l + r) / 2;

            if (idx <= m) {
                update(idx, val, node * 2, l, m);
            } else {
                update(idx, val, node * 2 + 1, m + 1, r);
            }

            st[node] = max(st[node * 2], st[node * 2 + 1]);
        }

        void update(int idx, int val) {
            update(idx, val, 1, 0, n);
        }

        int query(int L, int R, int node, int l, int r) {
            if (R < l || r < L) return 0;

            if (L <= l && r <= R) {
                return st[node];
            }

            int m = (l + r) / 2;

            return max(
                query(L, R, node * 2, l, m),
                query(L, R, node * 2 + 1, m + 1, r)
            );
        }

        int query(int l, int r) {
            if (l > r) return 0;
            return query(l, r, 1, 0, n);
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 0;
        unordered_set<int> all;

        // gather max coordinate + all obstacles
        for (auto& q : queries) {
            mx = max(mx, q[1]);
            if (q[0] == 1) {
                all.insert(q[1]);
            }
        }

        // all active positions initially
        set<int> pos;
        pos.insert(0);
        pos.insert(mx + 1);

        for (int x : all) {
            pos.insert(x);
        }

        SegTree seg(mx + 1);

        // build initial gap lengths
        for (auto it = next(pos.begin()); it != pos.end(); ++it) {
            int cur = *it;
            int left = *std::prev(it);

            if (cur <= mx) {
                seg.update(cur, cur - left);
            }
        }

        vector<bool> ans;

        // reverse processing
        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            auto& q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = pos.upper_bound(x);
                --it;

                int best = seg.query(0, x);
                int tail = x - *it;

                ans.push_back(max(best, tail) >= sz);
            } else {
                // remove obstacle in reverse
                int x = q[1];

                auto it = pos.find(x);

                int L = *std::prev(it);
                int R = *std::next(it);

                pos.erase(it);

                if (R <= mx) {
                    seg.update(R, R - L);
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};