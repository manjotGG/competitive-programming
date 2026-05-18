#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int idx = q.front();
                q.pop();

                if (idx == n - 1)
                    return steps;

                // Move left
                if (idx - 1 >= 0 && !vis[idx - 1]) {
                    vis[idx - 1] = true;
                    q.push(idx - 1);
                }

                // Move right
                if (idx + 1 < n && !vis[idx + 1]) {
                    vis[idx + 1] = true;
                    q.push(idx + 1);
                }

                // Same value jumps
                for (int next : mp[arr[idx]]) {
                    if (!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }

                // Optimization
                mp[arr[idx]].clear();
            }

            steps++;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    cout << "Minimum jumps: " << sol.minJumps(arr) << endl;

    return 0;
}