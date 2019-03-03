/*
 * @lc app=leetcode.cn id=204 lang=c
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (25.69%)
 * Total Accepted:    12.1K
 * Total Submissions: 46.6K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */
int isPrime(int num)
{
    int tmp = sqrt(num);
    for (int i = 2; i <= tmp; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int countPrimes(int n)
{
    int index = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            index++;
        }
    }
    return index;
}
