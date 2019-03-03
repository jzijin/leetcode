/*
 * @lc app=leetcode.cn id=231 lang=c
 *
 * [231] 2的幂
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (43.77%)
 * Total Accepted:    11.8K
 * Total Submissions: 26.8K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 20 = 1
 * 
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 24 = 16
 * 
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 * 
 */
/*
bool isPowerOfTwo(int n)
{
    if (n < 1)
    {
        return false;
    }
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            return false;
        }
    }
    return n == 1;
}
*/

// 用与运算更加的简单！！！！！
// 二的幂次 必定是 10 100 1000 10000 减一是 01 011 0111 01111 做一下与运算就变成了 0
bool isPowerOfTwo(int n)
{
    return n>0 && (n&(n-1)) == 0;
}