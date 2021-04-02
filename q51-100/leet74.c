/**
 * 编写一个高效的算法来判断m x n矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <mem.h>
#include "../support/sortintarray.c"


int findRow(int **matrix, int size, int target) {
    int low = -1, high = size - 1, mid;
    while (low < high) {
        mid = (low + high + 1) / 2;
        if (matrix[mid][0] <= target) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target) {
    int matrixIndex = findRow(matrix, matrixSize, target);
    if (matrixIndex == -1) {
        return false;
    }
    int low = 0, high = matrixColSize[matrixIndex] - 1;
    while (low <= high) {
        int mid = (low + high/* + 1*/) / 2;
        if (matrix[matrixIndex][mid] == target) {
            return true;
        } else if (matrix[matrixIndex][mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    int matrix[3][4] = {{1, 2,  3,  4},
                        {5, 6,  7,  8},
                        {9, 10, 11, 13}};
    printf("%d\n", sizeof(matrix) / sizeof(int));
    printf("%d\n", sizeof(*matrix) / sizeof(int));
    printf("%d\n", sizeof(matrix) / sizeof(*matrix));
    for (int i = 0; i < sizeof(matrix) / sizeof(*matrix); ++i) {
        printArray(*(matrix + i), sizeof(*(matrix + i)) / sizeof(int));
    }
    int colSize[sizeof(matrix) / sizeof(*matrix)];
    for (int i = 0; i < sizeof(matrix) / sizeof(*matrix); ++i) {
        colSize[i] = sizeof(matrix[i]) / sizeof(int);
    }
    int m = sizeof(matrix) / sizeof(*matrix), n = sizeof(*matrix) / sizeof(int);
    int **ma = malloc(m);
    for (int i = 0; i < m; ++i) {
        ma[i] = malloc(colSize[i] * sizeof(int));
    }
    printf("%d\n", sizeof(matrix) / sizeof(int));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ma[i][j] = matrix[i][j];
            printf("%d", ma[i][j]);
        }
    }
    printf("\n----------\n");
    bool ret = searchMatrix(ma, sizeof(matrix) / sizeof(*matrix), colSize, 11);
    printf("%s", ret ? "true" : "false");
    return 0;
}