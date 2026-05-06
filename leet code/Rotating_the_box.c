#include <stdio.h>
#include <stdlib.h>

char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize,
                    int* returnSize, int** returnColumnSizes) {

    int m = boxGridSize;
    int n = boxGridColSize[0];

    *returnSize = n;

    *returnColumnSizes = (int*)malloc(sizeof(int) * n);

    char** ans = (char**)malloc(sizeof(char*) * n);

    // initialize answer matrix
    for (int i = 0; i < n; i++) {

        (*returnColumnSizes)[i] = m;

        ans[i] = (char*)malloc(sizeof(char) * m);

        for (int j = 0; j < m; j++) {
            ans[i][j] = '.';
        }
    }

    // apply gravity row by row
    for (int i = 0; i < m; i++) {

        int empty = n - 1;

        for (int j = n - 1; j >= 0; j--) {

            if (boxGrid[i][j] == '*') {

                empty = j - 1;
            }

            else if (boxGrid[i][j] == '#') {

                boxGrid[i][j] = '.';

                boxGrid[i][empty] = '#';

                empty--;
            }
        }

        // rotate 90 degree clockwise
        for (int j = 0; j < n; j++) {

            ans[j][m - 1 - i] = boxGrid[i][j];
        }
    }

    return ans;
}

void printMatrix(char** matrix, int rows, int cols) {

    printf("[\n");

    for (int i = 0; i < rows; i++) {

        printf("  [");

        for (int j = 0; j < cols; j++) {

            printf("'%c'", matrix[i][j]);

            if (j != cols - 1)
                printf(", ");
        }

        printf("]");

        if (i != rows - 1)
            printf(",");

        printf("\n");
    }

    printf("]\n");
}

int main() {

    // Example input
    int m = 1;
    int n = 3;

    char** boxGrid = (char**)malloc(sizeof(char*) * m);

    for (int i = 0; i < m; i++) {
        boxGrid[i] = (char*)malloc(sizeof(char) * n);
    }

    // input: [["#", ".", "#"]]
    boxGrid[0][0] = '#';
    boxGrid[0][1] = '.';
    boxGrid[0][2] = '#';

    int boxGridColSize[1] = {n};

    int returnSize;
    int* returnColumnSizes;

    char** result = rotateTheBox(
        boxGrid,
        m,
        boxGridColSize,
        &returnSize,
        &returnColumnSizes
    );

    printf("Rotated Box:\n");

    printMatrix(result, returnSize, returnColumnSizes[0]);

    // free memory
    for (int i = 0; i < m; i++) {
        free(boxGrid[i]);
    }
    free(boxGrid);

    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}