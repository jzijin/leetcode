/*
 * @lc app=leetcode id=371 lang=c
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (51.25%)
 * Total Accepted:    124.8K
 * Total Submissions: 243.5K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */
int getSum(int a, int b)
{
    if (b == 0)
        return a;
    // 转化成无符号的才是正确的！！！
    int sum = a ^ b, carry = (uint)(a & b) << 1;
    return getSum(sum, carry);
}
