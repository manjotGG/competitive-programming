#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];  // store last seen index of characters
    for (int i = 0; i < 256; i++) lastIndex[i] = -1;

    int maxLength = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        char ch = s[right];

        // if character seen and inside current window
        if (lastIndex[ch] >= left) {
            left = lastIndex[ch] + 1;
        }

        lastIndex[ch] = right;

        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}