/**
 * 实现strStr()函数。
 * 给定一个haystack 字符串和一个 needle 字符串，
 * 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回 -1。
 */
#include <stdio.h>
#include <string.h>

#define END '\0'

//leetcode 报heap-buffer-overflow
int strStr1(char *haystack, char *needle) {
    if (*needle == END) {
        return 0;
    }
    if (strlen(haystack) < strlen(needle))return -1;
    int pos = -1;
    int sIndex = 0;
    int nIndex = 0;
    while (*(haystack + sIndex) != END && *(needle + nIndex) != END) {
        printf("%c", *(haystack + sIndex));
        if (*(haystack + sIndex) == *(needle + nIndex)) {
            if (pos == -1) {
                pos = sIndex;
            }
            nIndex++;
        } else {
            if (nIndex != 0) {
                int sTemp = sIndex;
                while (*(haystack + sTemp) == *(haystack + sTemp - 1) && sTemp > pos) { sTemp--; };
                if (sTemp == pos) {
                    pos++;
                } else {
                    sIndex = pos + 1;
                    nIndex = 0;
                    pos = -1;
                }
            }
        }
        sIndex++;
    }
    return *(needle + nIndex) == END ? pos : -1;
}

int strStr(char *haystack, char *needle) {
    if (END == *needle) {
        return 0;
    }
    int hayLen = strlen(haystack);
    int neeLen = strlen(needle);
    if (haystack < neeLen)return -1;
    int pos = -1;
    int nIndex = 0;
    for (int sIndex = 0; sIndex < hayLen; ++sIndex) {
        if (haystack[sIndex] == needle[nIndex]) {
            if (pos == -1) {
                pos = sIndex;
            }
            nIndex++;
        } else {
            if (nIndex != 0) {
                int sTemp = sIndex;
                for (sTemp; sTemp > pos; --sTemp) {
                    if (haystack[sTemp] != haystack[sTemp - 1]) {
                        break;
                    }
                }
                if (sTemp == pos) {
                    pos++;
                } else {
                    sIndex = pos + 1;
                    nIndex = 0;
                    pos = -1;
                }
            }
        }
        if (needle[nIndex] == END) break;
    }
    return *(needle + nIndex) == END ? pos : -1;
}

int strStr2(char *haystack, char *needle) {
    if (END == *needle) {
        return 0;
    }
    int hayLen = strlen(haystack);
    int neeLen = strlen(needle);
    if (haystack < neeLen) return -1;
    for (int i = 0; i < hayLen; i++) {
        int k = 0;
        for (int j = i; j < hayLen; j++, k++) {
            if (haystack[j] != needle[k]) {
                break;
            }
            if (k == neeLen - 1) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    printf("%d\n", strStr("aabaabbbaabbbbabaaab", "abaa"));
    printf("%d\n", strStr1("aabaabbbaabbbbabaaab", "abaa"));
    printf("%d\n", strStr2("aabaabbbaabbbbabaaab", "abaa"));
    printf("%d\n", strStr("mississippi", "pi"));
    printf("%d\n", strStr1("mississippi", "pi"));
    printf("%d\n", strStr2("mississippi", "pi"));
    printf("%d\n", strStr("helllo", "lo"));
    printf("%d\n", strStr1("helllo", "lo"));
    printf("%d\n", strStr2("helllo", "lo"));
    return 0;
}