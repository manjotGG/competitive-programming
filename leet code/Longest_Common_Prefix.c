#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";

    // Take first string as reference
    char *prefix = strs[0];

    for (int i = 0; i < strlen(prefix); i++) {
        char current = prefix[i];

        // Compare with all other strings
        for (int j = 1; j < strsSize; j++) {
            if (i >= strlen(strs[j]) || strs[j][i] != current) {
                // Create result string
                char *result = (char*)malloc(i + 1);
                strncpy(result, prefix, i);
                result[i] = '\0';
                return result;
            }
        }
    }

    return prefix;
}