/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (45.91%)
 * Total Accepted:    15.4K
 * Total Submissions: 33.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* addBinary(char* a, char* b) {
    int a_length = strlen(a);
    int b_length = strlen(b);
    int max_length = a_length > b_length ? a_length : b_length;
    char *target = (char *)malloc(sizeof(char) * (max_length + 1));
    a_length -= 1;
    b_length -= 1;
    int jinwei = 0;
    int sum = 0;
    while (1)
    {
        if (a_length < 0 && b_length < 0)
        {
            break;
        }
        if (a_length < 0 && b_length >= 0)
        {
            sum = b[b_length] + jinwei;
        }
        else if (a_length >= 0 && b_length < 0)
        {
            sum = a[a_length] + jinwei;
        }
        else
        {
            sum = a[a_length] + b[b_length] + jinwei;
        }

        if (sum == 2)
        {
            target[max_length] = 0;
            jinwei = 1;
        }
        else if (sum == 3)
        {
            target[max_length] = 1;
            jinwei = 1;
        }
        else
        {
            target[max_length] = sum;
        }

        a_length--;
        b_length--;
        max_length--;
    }
    return target;

}
int main()
{
    char* target = addBinary("11", "11");
    printf("%c", target[0]);
}
