/**
 * 给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END '\0'
static char **characters;

char getChar(char *c, int j) {
    return c[j];
}

char getChara(int index) {
    char *c = characters[index];
    for (int i = 0; i < strlen(c); ++i) {
        printf("%c", getChar(c, i));
    }
    printf("\n");
}

char **mergeChar(char **a, int aSize, char *b, char **ret) {
    int bSize = strlen(b);
    printf("p %p \n", ret);
    for (int i = 0; i < aSize; ++i) {
        for (int j = 0; j < bSize; ++j) {
            int l = strlen(a[i]);
            printf("%s\n", a[i]);
            char c[l];
            memcpy(c, a[i], l);
            char x = b[j];
            char *temp = &x;
            strcat(c, temp);
            printf("%s\n", c);
            *ret = malloc(l + 2);
            strcpy(*ret, c);
            printf("%s\n", *ret);
            ret++;
        }
        printf("-----\n");
    }
    return ret;
}

int getCharacLen(char c) {
    if (c == '7' || c == '9') return 4;
    return 3;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char *digits, int *returnSize) {
    int len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 1;
    char **ret;
    for (int i = 0; i < len; ++i) {
        (*returnSize) *= getCharacLen(digits[i]);
    }
    ret = (char **) malloc((*returnSize) * sizeof(char*));
    int step = *returnSize;
//    memset(ret, 0, *returnSize);
    for (int i = 0; i < *returnSize; ++i) {
        *(ret + i) = malloc((len + 1) * sizeof(char));
        ret[i][len] = END;
    }
    for (int i = 0; i < len; ++i) {
        step /= getCharacLen(digits[i]);
        for (int j = 0; j < *returnSize; ++j) {
            ret[j][i] = characters[digits[i] - '2'][(j / step) % getCharacLen(digits[i])];
        }
    }
    return ret;
}

int main() {
    characters = malloc(26);
    characters[0] = "abc";
    characters[1] = "def";
    characters[2] = "ghi";
    characters[3] = "jkl";
    characters[4] = "mno";
    characters[5] = "pqrs";
    characters[6] = "tuv";
    characters[7] = "wxyz";
    char *numbers = "23";
    int *size = malloc(1);
    char **ret = letterCombinations(numbers, size);
    for (int i = 0; i < *size; ++i) {
        printf("%s\n", ret[i]);
    }
//    char a[10] = "a";
//    char b[10] = "b";
//    strcat(a, b);
//    printf("%s", characters[0]);
//    char **ret = malloc(1000);
//    printf("p %p\n", ret);
//    mergeChar(characters, 2, "xy", ret);
    return 0;
}