#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string processStr(string s) {
        string res;

        for (char c : s) {
            if (islower(c)) {
                res.push_back(c);
            }
            else if (c == '*') {
                if (!res.empty()) {
                    res.pop_back();
                }
            }
            else if (c == '#') {
                res += res;
            }
            else if (c == '%') {
                reverse(res.begin(), res.end());
            }
        }

        return res;
    }
};