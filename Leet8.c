/**
 * 读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-integer-atoi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * @param s
 * @return
 */
#include <stdbool.h>
#include <limits.h>

int myAtoi(char *s) {
    bool spaceIsFirst = true;
    bool isNegative = false;
    double result = 0;
    while (*s != '\0') {
        if (*s >= '0' && *s <= '9') {
            spaceIsFirst = false;
            int num = *s - '0';
            result = result * 10 + num;
        } else {
            if (*s == ' ') {
                if (spaceIsFirst) {
                    *(s++);
                    continue;
                } else {
                    break;
                }
            } else if ((*s == '-' || *s == '+') && spaceIsFirst) {
                spaceIsFirst = false;
                isNegative = *s == '-';
                *(s++);
                continue;
            } else {
                break;
            }

        }
        s++;
    }
    if (isNegative) {
        result = -result;
    }

    if (result > INT_MAX) {
        return INT_MAX;
    } else if (result < INT_MIN) {
        return INT_MIN;
    } else {
        return (int) result;
    }
}
