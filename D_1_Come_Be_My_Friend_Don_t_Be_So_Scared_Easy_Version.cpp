#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;               // m = 0 in this version
        vector<pair<int,int> > res;
        if (n == 1) {
            // nothing needed
        } else if (n == 2) {
            res.push_back(make_pair(1, 1));
        } else if (n % 2 == 0) {
            res.push_back(make_pair(1, 2));
            for (int l = 2; l + 2 <= n - 2; l += 2) res.push_back(make_pair(l, l + 2));
            res.push_back(make_pair(n - 2, n - 1));
        } else {
            res.push_back(make_pair(1, 1));
            for (int l = 1; l + 2 <= n - 2; l += 2) res.push_back(make_pair(l, l + 2));
            res.push_back(make_pair(n - 2, n - 1));
        }
        cout << res.size() << '\n';
        for (size_t i = 0; i < res.size(); i++)
            cout << res[i].first << ' ' << res[i].second << '\n';
    }
    return 0;
}