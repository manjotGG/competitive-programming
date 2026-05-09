#include <stdio.h>
#include <stdlib.h>

int** rotateGrid(int** grid, int gridSize, int* gridColSize,
                 int k, int* returnSize, int** returnColumnSizes) {

    int m = gridSize;
    int n = gridColSize[0];

    int** ans = (int**)malloc(sizeof(int*) * m);

    for (int i = 0; i < m; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++) {
            ans[i][j] = grid[i][j];
        }
    }

    int layers = (m < n ? m : n) / 2;

    for (int layer = 0; layer < layers; layer++) {

        int top = layer;
        int left = layer;
        int bottom = m - layer - 1;
        int right = n - layer - 1;

        int size = 2 * (bottom - top + right - left);

        int* arr = (int*)malloc(sizeof(int) * size);

        int idx = 0;

        // top row
        for (int j = left; j <= right; j++)
            arr[idx++] = grid[top][j];

        // right column
        for (int i = top + 1; i <= bottom - 1; i++)
            arr[idx++] = grid[i][right];

        // bottom row
        for (int j = right; j >= left; j--)
            arr[idx++] = grid[bottom][j];

        // left column
        for (int i = bottom - 1; i >= top + 1; i--)
            arr[idx++] = grid[i][left];

        int rot = k % size;

        idx = 0;

        // top row
        for (int j = left; j <= right; j++) {
            ans[top][j] = arr[(idx + rot) % size];
            idx++;
        }

        // right column
        for (int i = top + 1; i <= bottom - 1; i++) {
            ans[i][right] = arr[(idx + rot) % size];
            idx++;
        }

        // bottom row
        for (int j = right; j >= left; j--) {
            ans[bottom][j] = arr[(idx + rot) % size];
            idx++;
        }

        // left column
        for (int i = bottom - 1; i >= top + 1; i--) {
            ans[i][left] = arr[(idx + rot) % size];
            idx++;
        }

        free(arr);
    }

    *returnSize = m;

    *returnColumnSizes = (int*)malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++)
        (*returnColumnSizes)[i] = n;

    return ans;
}

void printMatrix(int** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int rows = 4;
    int cols = 4;

    int data[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int** grid = (int**)malloc(sizeof(int*) * rows);

    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(sizeof(int) * cols);

        for (int j = 0; j < cols; j++) {
            grid[i][j] = data[i][j];
        }
    }

    int gridColSize[4] = {4, 4, 4, 4};

    int returnSize;
    int* returnColumnSizes;

    int k = 2;

    int** result = rotateGrid(
        grid,
        rows,
        gridColSize,
        k,
        &returnSize,
        &returnColumnSizes
    );

    printf("Rotated Grid:\n");
    printMatrix(result, returnSize, cols);

    // free memory
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
        free(result[i]);
    }

    free(grid);
    free(result);
    free(returnColumnSizes);

    return 0;
}