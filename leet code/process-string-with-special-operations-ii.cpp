#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);
        const long long LIM = (long long)1e15 + 5;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                len[i + 1] = min(LIM, len[i] + 1);
            } 
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            } 
            else if (c == '#') {
                len[i + 1] = min(LIM, len[i] * 2);
            } 
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        long long pos = k;

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (pos == len[i + 1] - 1)
                    return c;
            }
            else if (c == '#') {
                if (len[i] > 0)
                    pos %= len[i];
            }
            else if (c == '%') {
                if (len[i] > 0)
                    pos = len[i] - 1 - pos;
            }
            // '*' -> pos unchanged
        }

        return '.';
    }
};