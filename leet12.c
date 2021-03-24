#include <stdio.h>
#include <mem.h>

char *type[4] = {"IVX", "XLC", "CDM", "MMM"};
static int numIndex = 0;

void appendChar(char *p, int num, int t) {
    if (num == 0) {
        return;
    }
    char *roma = type[t];
    if (num <= 3) {
        for (int i = 0; i < num; ++i) {
            p[numIndex++] = roma[0];
        }
    } else if (num <= 5) {
        if (num == 4) {
            p[numIndex++] = roma[0];
            p[numIndex++] = roma[1];
        } else {
            p[numIndex++] = roma[1];
        }
    } else if (num <= 8) {
        p[numIndex++] = roma[1];
        for (int i = 0; i < num - 5; ++i) {
            p[numIndex++] = roma[0];
        }
    } else {
        p[numIndex++] = roma[0];
        p[numIndex++] = roma[2];
    }
}

char *intToRoman(int num) {
    if (num <= 0) {
        return "";
    }
    static char ret[50] = {'\0'};

    int ints[4];
    int i = 0;
    while (num != 0) {
        ints[i] = num % 10;
        num = num / 10;
        i++;
    }
    for (--i; i >= 0; --i) {
        appendChar(ret, ints[i], i);
    }
/*
    int i = 0;
    int k = num / 1000;
    int remainder = num % 1000;
    while (k > 0) {
        ret[i] = 'M';
        i++;
        k--;
    }
    int h = remainder / 100;*/
    return ret;
}

int main() {
    printf("%s\n", intToRoman(58));
    return 0;
}