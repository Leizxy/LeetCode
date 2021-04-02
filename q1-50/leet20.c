/**
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']'的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char *s) {
    int len = strlen(s);
    if (len <= 0) {
        return false;
    }
    bool flag = true;
    char *stack = malloc(len);
    int index = 0;
    while (*s != '\0') {
        if (*s == '(' || *s == '[' || *s == '{') {
            char t = *s;
            stack[index] = t;
            index++;
        } else {
            if ((*s == ')' && stack[index - 1] == '(')
                || (*s == ']' && stack[index - 1] == '[')
                || (*s == '}' && stack[index - 1] == '{')) {
                stack[index] = '\0';
                index--;
            } else {
                flag = false;
                break;
            }
        }
        s++;
    }
    return index == 0 ? flag : false;
}

int main() {
    printf("%d\n", isValid(")["));
    printf("%d\n", isValid("()(){}"));
    printf("%d\n", isValid("{([}()])"));
    printf("%d\n", isValid("{([()]{})}"));
    return 0;
}