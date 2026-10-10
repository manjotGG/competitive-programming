#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        bool aliceWins = false;

        for (int i = 0; i <= n; i++) {
            if (freq[i] == 2 * k - 1) {
                aliceWins = true;
                break;
            }

            if (freq[i] < 2 * k) {
                break;
            }
        }

        cout << (aliceWins ? "YES" : "NO") << '\n';
    }

    return 0;
}