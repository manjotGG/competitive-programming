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
#include <cstring>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int odd = 0, even = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            if (x % 2 == 0)
                even++;
            else
                odd++;
        }

        if ((even == 1 && odd == 1) ||
            (even == 0 && odd == 3)) {
            cout << "Larpity\n";
        } else {
            cout << "Moggity\n";
        }
    }

    return 0;
}

