/**
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。
 */

#include <stdio.h>

double mul(double x, long long n) {
    double ret = 1;
    double temp = x;
    while (n > 0) {
        if (n % 2 == 1) {
            ret *= temp;
        }
        temp *= temp;
        n /= 2;
    }
    return ret;
}

double myPow(double x, int n) {
    long long l = n;
    return n > 0 ? mul(x, l) : 1 / mul(x, -l);
}

int main() {
    printf("%f", myPow(0.1, 2));
    return 0;
}