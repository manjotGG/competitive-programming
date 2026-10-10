#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) {
            cout << 0 << '\n';
        }
        else if (b <= a && (a - b) % 2 == 0) {
            cout << a << '\n';
        }
        else if (b <= a + 1 && (a + 1 - b) % 2 == 0) {
            cout << a + 1 << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }

    return 0;
}