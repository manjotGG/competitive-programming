#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s);
    if (numRows == 1 || n <= numRows) return s;

    // Allocate array of strings (rows)
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* colSizes = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)malloc((n + 1) * sizeof(char));
    }

    int currRow = 0;
    int direction = 1; // down

    for (int i = 0; i < n; i++) {
        rows[currRow][colSizes[currRow]++] = s[i];

        if (currRow == 0)
            direction = 1;
        else if (currRow == numRows - 1)
            direction = -1;

        currRow += direction;
    }

    // Build final string
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            result[idx++] = rows[i][j];
        }
    }

    result[idx] = '\0';
    return result;
}