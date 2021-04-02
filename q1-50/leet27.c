#include <stdio.h>

int removeElement(int *nums, int numsSize, int val) {
    printf("%d\n", numsSize);
    int move = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[move] = nums[i];
            move++;
        }
    }
//    nums[move] = NULL;
    printf("%d\n", move);
    return move;
}

int main() {
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int a = removeElement(nums, sizeof(nums) / sizeof(int), 1);
    for (int i = 0; i < a; ++i) {
        printf("%d", nums[i]);
    }
    printf("\n%d", a);
    return 0;
}