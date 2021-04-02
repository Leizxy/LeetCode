/**
 *给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 */
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <minmax.h>

#define MIN(a, b) (a < b ? a : b)

//单调栈
int trap1(int *height, int heightSize) {
    int *stack = malloc(heightSize * sizeof(int));
    memset(stack, -1, heightSize * sizeof(int));
    int top = 0, ret = 0;
    stack[top] = 0;
    for (int i = 0; i < heightSize; ++i) {
        //出栈
        while (top > 0 && height[i] > height[stack[top - 1]]) {
            int w = 0, h = 0;//间隔
            if (top >= 2) {
                w = i - stack[top - 2] - 1;
                h = min(height[i], height[stack[top - 2]]) - height[stack[top - 1]];
            } else {
                h = 0;
            }
            ret += w * h;
            top--;
            if (top < 0) {
                top = 0;
            }
        }
        stack[top++] = i;
    }
    return ret;
}

//双指针
int trap(int *height, int heightSize) {
    int lMax, rMax, l, r, ret = 0;
    l = 0;
    r = heightSize - 1;
    while (l < r) {
        while (l < r && height[l] <= height[l + 1]) {
            l++;
        }
        while (l < r && height[r] <= height[r - 1]) {
            r--;
        }
        lMax = height[l];
        rMax = height[r];
        if (lMax < rMax) {
            while (l < r && height[l] <= lMax) {
                ret += lMax - height[l];
                ++l;
            }
        } else {
            while (l < r && height[r] <= rMax) {
                ret += rMax - height[r];
                r--;
            }
        }
    }
    return ret;
}

int main() {
    int ints[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap1(ints, sizeof(ints) / sizeof(int)));
    printf("%d\n", MIN(1, 2));
    return 0;
}