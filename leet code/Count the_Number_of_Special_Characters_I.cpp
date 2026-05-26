#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, upper;

        for (char ch : word) {
            if (islower(ch))
                lower.insert(ch);
            else
                upper.insert(ch);
        }

        int count = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (lower.count(ch) && upper.count(ch - 'a' + 'A')) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    string word;
    cin >> word;

    cout << sol.numberOfSpecialChars(word) << endl;

    return 0;
}