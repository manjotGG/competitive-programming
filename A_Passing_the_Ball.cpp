#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<bool> visited(n, false);
        int current = 0;
        int count = 0;
        while (!visited[current]) {
            visited[current] = true;
            count++;

            if(s[current] == 'R') {
                current = (current + 1);
            } else {
                current = (current - 1);
            }
        }
        cout << count << endl;
    }


}