#include <iostream>

using namespace std;
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";

        // Try every possible length from shortest to longest
        for (int len = 1; len <= n; len++) {
            bool found = false;

            for (int i = 0; i + len <= n; i++) {
                string sub = s.substr(i, len);

                int ones = 0;
                for (char c : sub) {
                    if (c == '1') ones++;
                }

                // Beautiful substring
                if (ones == k) {
                    if (!found || sub < ans) {
                        ans = sub;
                    }
                    found = true;
                }
            }

            // First length where we found a valid substring
            // is automatically the shortest
            if (found) return ans;
        }

        return "";
    }
};