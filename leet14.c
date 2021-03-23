/**
 * 编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
 */
#include <stdio.h>
#include <string.h>

char *longestCommonPrefix1(char **strs, int strsSize) {
    printf("%c\n", strs[0][0]);
    strs[0][0] = 'f';
//    printf("%s\n", *strs);
//    printf("%s\n", *(strs + 2));
    printf("%s\n", *(strs + 0));
    if (strsSize == 0) {
        return "";
    }
    if (strsSize == 1) {
        return *strs;
    }
    strsSize--;
    printf("%d\n", strsSize);
    char *prefix = *(strs + strsSize);
    int pos = strlen(prefix);
    if (pos == 0) {
        char *d = {"\0"};
        return d;
    }
    while (--strsSize >= 0) {
        printf("%d\n", strsSize);
        printf("%s\n", *(strs + strsSize));
        printf("%p\n", *(strs + strsSize));
        int i = 0;
        while (*(*(strs + strsSize) + i) == *(prefix + i) && *(prefix + i) != '\0') {
            i++;
        }
        pos = pos < i ? pos : i;
        if (pos == 0) {
            return "";
        }
//        prefix[pos] = '\0';
    }
    return prefix;
}

char *longestCommonPrefix(char **strs, int strsSize) {
    int flag = 1;
    if(strsSize == 0)
    {
        return "";
    }
    for (int j = 0; j < strlen(strs[0]) && flag; ++j) {
        for (int i = 0; i < strsSize; ++i) {
            if (strs[i][j] != strs[0][j]) {
                strs[0][j] = '\0';
                flag = 0;
                break;
            }
        }
    }
    return strs[0];
}

int main() {
//    char *strs[] = {"dog", "racecar", "car"};
    char *strs[] = {"ab", "a"};
//    strs[0][0] = 'f';
//    printf("%s\n", *strs);
    printf("result is %s\n", longestCommonPrefix(strs, 2));
    return 0;
}