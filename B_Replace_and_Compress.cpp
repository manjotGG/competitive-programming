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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();
        bool canIncrease = false;
        bool canDecrease = false;

        for (int i = 1; i < n - 1; i++) {
            if (s[i - 1] == s[i + 1]) {
                if (s[i] == s[i - 1]) {
                    canIncrease = true;
                } else {
                    canDecrease = true;
                }
            }
        }

        cout << 1 + canIncrease + canDecrease << '\n';
    }

    return 0;
}
