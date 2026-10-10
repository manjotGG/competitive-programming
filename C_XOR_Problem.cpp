#include <stdio.h>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int m = 1;
        while (m <= n) m <<= 1;

        vector<int> a;
        for (int i = 0; i < m; i++) {
            a.push_back(0);

            if (i + 1 < m) {
                int g1 = i ^ (i >> 1);
                int j = i + 1;
                int g2 = j ^ (j >> 1);
                a.push_back(g1 ^ g2);
            }
        }

        cout << a.size() << '\n';
        for (int i = 0; i < (int)a.size(); i++) {
            cout << a[i] << (i + 1 == (int)a.size() ? '\n' : ' ');
        }
    }

    return 0;
}