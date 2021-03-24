
/**
 *
给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。

注意：n 的值小于15000。
 */
#include <stdio.h>
#include <stdbool.h>
#include <minmax.h>

bool find132pattern(int *nums, int numsSize) {
    if (numsSize < 3) {
        return false;
    }
    int j;
    int leftMin = nums[0];
    for (j = 1; j < numsSize - 1; ++j) {
        if (nums[j] > leftMin) {
            for (int k = j + 1; k < numsSize; ++k) {
                if (nums[k] < nums[j] && nums[k] > leftMin) {
                    return true;
                }
            }
        }
        leftMin = min(leftMin, nums[j]);
    }

//超时
    /*while (j < numsSize - 1) {
        for (i = j - 1; i < j && i >= 0; i--) {
            for (k = j + 1; k < numsSize; k++) {
                printf("%d - %d - %d\n", i, j, k);
                printf("%d - %d - %d\n", nums[i], nums[j], nums[k]);
                if (nums[i] < nums[k] && nums[k] < nums[j]) {
                    return true;
                }
            }
        }
        j++;
    }*/

    return false;
}

int main() {
    int i[20] = {3, 1, 4, 2};
    printf("%s\n", find132pattern(i, 4) ? "true" : "false");
    return 0;
}