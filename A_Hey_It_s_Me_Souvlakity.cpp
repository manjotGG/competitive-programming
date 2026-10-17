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
        int n;
        string s;
        cin >> n >> s;

        int first = -1, last = -1, ones = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (first == -1) first = i;
                last = i;
                ones++;
            }
        }

        if (ones == 1) {
            cout << 0 << '\n';
        } else if (ones == 2) {
            cout << 1 << '\n';
        } else {
            cout << last - first << '\n';
        }
    }

    return 0;
}

