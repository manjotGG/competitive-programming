#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> depth(n + 1, -1);
        queue<int> q;

        q.push(1);
        depth[1] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    q.push(v);
                }
            }
        }

        int mxDepth = 0;

        for (int i = 1; i <= n; i++) {
            mxDepth = max(mxDepth, depth[i]);
        }

        if (mxDepth == 0) return 0;

        return modPow(2, mxDepth -1);
    }
};