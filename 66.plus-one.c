/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (37.15%)
 * Total Accepted:    35.1K
 * Total Submissions: 94.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int max_num = digitsSize - 1;
    if (digits[max_num] != 9)
    {
        digits[max_num] += 1;
        *returnSize = digitsSize;
        return digits;
    }

    int flag = 1;// flag ==1 每一位都是9
    for (int i = 0; i < digitsSize; i++)
    {
        if (digits[i] != 9)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        *returnSize = digitsSize + 1;
        int *new_digits = (int *)malloc(sizeof(int) * (digitsSize + 1));
        new_digits[0] = 1;
        for (int i = 1; i < digitsSize + 1; i++)
        {
            new_digits[i] = 0;
        }        
        return new_digits;
    }
    else
    {
        *returnSize = digitsSize;
        digits[max_num] = 0;
        while (1)
        {
            if (digits[max_num - 1] != 9)
            {
                digits[max_num - 1] += 1;
                break;
            }
            else
            {
                digits[max_num - 1] = 0;
                max_num--;
            }
        }        
    }
    return digits;
}
    
