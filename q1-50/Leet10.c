/**
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define END '\0'

bool isMatch(char *s, char *p) {
    if (!(*s || *p)) return true;
    else if (!*p) return false;
    else {
        int sLen = strlen(s);
        int pLen = strlen(p);
        bool *match;
        match = calloc(sLen + 1, sizeof(bool));
        match[sLen] = true;
        int i = pLen - 1,j;
        while (i >= 0) {
            if (p[i] == '*') {
                i--;
                if (i < 0 || p[i] == '*') {
                    return false;
                } else {
                    for (j = sLen - 1; j >= 0; j--) {
                        if ((p[i] == s[j]) || (p[i] == '.')) {
                            match[j] = match[j + 1] || match[j];
                        }
                    }
                    i--;
                }
            } else {
                for (j = 0; j < sLen; ++j) {
                    if ((s[j] == p[i] || p[i] == '.')) {
                        match[j] = match[j + 1];
                    } else {
                        match[j] = false;
                    }
                }
                match[sLen] = false;
                i--;
            }
            for (int x = 0; x < sLen + 1; ++x) {
                printf("%s ", match[x] ? "true " : "false");
            }
            printf("\n");
        }
        return match[0];
    }
}

bool isMatch2(char *s, char *p) {
    bool result = true;
    char *curP;
    while (result) {
        if (*s == END && *p == END) {
            break;
        } else if (*p == END) {
            result = false;
            continue;
        }
        curP = p;
        printf("s - %c, p - %c%c\n", *s, *p, *(p + 1) == '*' ? '*' : ' ');
        bool isAny = *p == '.';
        bool isMore = *(p + 1) == END ? false : *(p + 1) == '*';
        if (isAny && isMore) {// .*
            while (*s != END) {
                s++;
            }
            p += 2;
            result = true;
            continue;
        } else if (isAny) { // .
            result = true;
            p++;
            s++;
            continue;
        } else if (isMore) { // x*
            bool haveMove = false;
            while (*s == *p) {
                haveMove = true;
                s++;
            }
            if (*(p + 1) != END) {
                p += 2;
            } else {
                p++;
            }
            if (*p != END) {
                if (*s == END && haveMove) {
                    s--;
                }
            }
            result = true;
            continue;
        } else { // x
            result = *s == *p;
            s++;
            p++;
            continue;
        }
    }
    return result;
}