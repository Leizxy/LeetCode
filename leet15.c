/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <malloc.h>
#include "support/sortintarray.c"

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    selectSort(nums, numsSize);
    printArray(nums, numsSize);
    int cur = 0, start, end;
    //分配返回数组
//    int **ret = (int **) malloc(numsSize * numsSize * sizeof(int *));
    //leet 上这行代码可以，但是这里会报错，环境不一致的问题？
//    *returnColumnSizes = (int *) malloc(numsSize * numsSize * sizeof(int));

    while (nums[cur] <= 0 && cur < numsSize - 2) {
        start = cur + 1;
        end = numsSize - 1;
        while (start < end) {
            int sum = nums[start] + nums[cur] + nums[end];
            if (sum == 0) {
                printf("%d,%d,%d\n", nums[cur], nums[start], nums[end]);
                (*returnSize)++;
                while (nums[start] == nums[++start] && start < end);
                while (nums[end] == nums[--end] && start < end);
            } else if (sum > 0) {
                end--;
            } else {
                start++;
            }
        }
        while (nums[cur] == nums[++cur] && nums[cur] <= 0 && cur < numsSize - 2);
    }
    printf("%d\n", *returnSize);
    return returnColumnSizes;
}

int main() {
    int data[] = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    int *size = malloc(sizeof(int));
    int **column;
    threeSum(data, sizeof(data) / sizeof(data[0]), size, column);
    printf("%d", *size);
    /*for (int i = 0; i < *size; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d,", column[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}