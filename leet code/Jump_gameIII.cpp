#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(vector<int>& arr, int idx, vector<bool>& visited) {
        // Out of bounds or already visited
        if (idx < 0 || idx >= arr.size() || visited[idx]) {
            return false;
        }

        // If we reach value 0
        if (arr[idx] == 0) {
            return true;
        }

        visited[idx] = true;

        // Move forward or backward
        return dfs(arr, idx + arr[idx], visited) ||
               dfs(arr, idx - arr[idx], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, start, visited);
    }
};

int main() {
    Solution sol;

    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    int start = 5;

    if (sol.canReach(arr, start)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}