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

#define ZERO '\0'

char *str;
char *reg;
int strLen;
int regLen;
int strIndex = 0;
int regIndex = 0;

bool matchBlock(bool isMore, bool isAny) {
    printf("s - %c, p - %c%c\n", *str, *reg, *(reg + 1) == '*' ? '*' : ' ');
    printf("isMore - %s, isAny - %s\n", isMore ? "true" : "false", isAny ? "true" : "false");
    if (*str == ZERO && *reg == ZERO) {
        return true;
    } else if (*str == ZERO) {
        if (!isMore) {
            return *(--str) == *reg;
        }
    } else if (*reg == ZERO) {
        return *(str - 1) == *(reg - 1);
    }
    if (isMore && isAny) { // .*
        reg += 2;
        if (*reg == ZERO) {
            return true;
        } else {
            str++;
            return matchBlock(*(reg + 1) == '*', *reg == '.');
        }
    } else if (isAny) { // .
        if (*str != ZERO) {
            return true;
        } else {
            str++;
            reg++;
            return matchBlock(*(reg + 1) == '*', *reg == '.');
        }
    } else if (isMore) { // x*
        while (*str == *reg) {
            str++;
        }
        reg += 2;
        return matchBlock(*(reg + 1) == '*', *reg == '.');
    } else { // x
        if (*str != *reg) {
            return false;
        } else {
            str++;
            reg++;
            return matchBlock(*(reg + 1) == '*', *reg == '.');
        }
    }
}

bool isMoreBool() {
    if (regIndex + 1 >= regLen) {
        return false;
    }
    if (reg[regIndex] == '*') {
        return true;
    }
    return false;
}

bool matchChar(bool isMore, bool isAny) {
    printf("s - %c, p - %c%c\n", str[strIndex], reg[regIndex], reg[regIndex + 1] == '*' ? '*' : ' ');
    printf("%d,%d\n", strIndex, regIndex);
    printf("isMore - %s, isAny - %s\n", isMore ? "true" : "false", isAny ? "true" : "false");
    if (strIndex == strLen && regIndex == regLen) {
        return true;
    } else if (strIndex == strLen) {
        if (!isMore) {
            return str[--strIndex] == reg[regIndex];
        }
    } else if (regIndex == regLen) {
        return str[strIndex - 1] == reg[regIndex - 1];
    }
    if (isMore && isAny) { // .*
        regIndex += 2;
        if (regIndex == regLen) {
            return true;
        } else {
            strIndex++;
            
            return matchChar(isMoreBool(),
                             regIndex < regLen ? reg[regIndex] == '.' : false);
        }
    } else if (isAny) { // .
        strIndex++;
        regIndex++;
        return matchChar(isMoreBool(),
                         regIndex < regLen ? reg[regIndex] == '.' : false);
    } else if (isMore) { //x*
        while (str[strIndex] == reg[regIndex]) {
            strIndex++;
        }
        regIndex += 2;
        return matchChar(isMoreBool(),
                         regIndex < regLen ? reg[regIndex] == '.' : false);
    } else {
        if (str[strIndex] != reg[regIndex]) {
            return false;
        } else {
            strIndex++;
            regIndex++;
            return matchChar(isMoreBool(),
                             regIndex < regLen ? reg[regIndex] == '.' : false);
        }
    }
}

bool isMatch(char *s, char *p) {
    str = s;
    reg = p;
    strLen = strlen(str);
    regLen = strlen(reg);
    printf("%d,%d\n", strLen, regLen);
//    return matchBlock(*(reg + 1) == '*', *reg == '.');
    return matchChar(isMoreBool(),
                     regIndex < regLen ? reg[regIndex] == '.' : false);
}