/**
 * 给定一个包括n 个整数的数组nums和 一个目标值target。找出nums中的三个整数
 * ，使得它们的和与target最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 */
#include <stdio.h>
#include <minmax.h>
#include <math.h>
#include "../support/sortintarray.c"

int threeSumClosest(int *nums, int numsSize, int target) {
    if (numsSize == 3) {
        return nums[0] + nums[1] + nums[2];
    }
//    selectSort(nums, numsSize);
    printArray(nums, numsSize);
    int cur = 0, start, end;
    int targetDiff = abs(nums[0] + nums[1] + nums[2] - target);
    int ret;
    while (cur < numsSize - 2) {
        start = cur + 1;
        while (start < numsSize - 1) {
            end = start + 1;
            while (end < numsSize) {
                int sum = nums[cur] + nums[start] + nums[end];
                int diff = abs(sum - target);
                if (diff <= targetDiff) {
                    ret = sum;
                    targetDiff = diff;
                    if (targetDiff == 0) {
                        return ret;
                    }
                }
                end++;
            }
            start++;
        }
        cur++;
    }
    return ret;
}

int main() {
    int data[] = {1, 2, 4, 8, 16, 32, 64, 128};
//    int data[] = {-1, 2, 1, -4};
//    int data[] = {1,1,1,1};
    printf("%d", threeSumClosest(data, sizeof(data) / sizeof(data[0]), 82));
    return 0;
}