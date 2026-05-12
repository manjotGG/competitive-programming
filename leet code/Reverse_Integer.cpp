#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    
    int reverse(int x) {

        int rev = 0;

        while (x != 0) {

            int digit = x % 10;

            // overflow check
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
                return 0;

            rev = rev * 10 + digit;

            x /= 10;
        }

        return rev;
    }
};

int main() {

    Solution obj;

    int x;
    cin >> x;

    cout << obj.reverse(x) << endl;

    return 0;
}