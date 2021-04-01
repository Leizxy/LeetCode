#include <stdio.h>

int cal(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 3) {
        return 1;
    } else if (n < 3) {
        return 1;
    } else {
        if (n == 4) {
            return -2;
        }
        if (n == 5) {
            return 0;
        }
        return cal(n - 4);
    }
}

int clumsy(int N) {
    if (N > 3) {
        return N * (N - 1) / (N - 2) + cal(N - 3);
    } else if (N == 3) {
        return 6;
    } else {
        return N;
    }
}

int main() {
    printf("ret %d\n", clumsy(8));
    printf("ret %d\n", 8 * 7 / 6 + 5 - 4 * 3 / 2 + 1);
    printf("ret %d\n", 11 + 7 - 7 + 3 - 2 * 1);
    return 0;
}

// 5 * 4 / 3 + 2 - 1    = 5 * 4 / 3 + 2 - 1 ( N= 5, 9)
// 4 * 3 / 2 + 1        = 4 * 3 / 2 + 1 - 0 ( N= 4, 8)
// 3 * 2 / 1            = 3 * 2 / 1 + 0 - 0 ( N= 3, 7)
// 2 * 1                = 2 * 1 / 1 + 0 - 0 ( N= 2, 6)
// 1                    = 1 * 1 / 1 + 0 - 0 ( N= 1, 5)

// n - (n-1)(n-2)/(n-3)
// (n2 - 3n - (n2 - 3n + 2)) / (n-3)
// -2 / (n-3) ? 2/(3-n)
// n = 1 -> 1, 2 -> 2
// n = 4(2) ,5(1),6(<1)