/*
 * @lc app=leetcode.cn id=202 lang=c
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (51.35%)
 * Total Accepted:    11K
 * Total Submissions: 21.2K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
 * 1。如果可以变为 1，那么这个数就是快乐数。
 * 
 * 示例: 
 * 
 * 输入: 19
 * 输出: true
 * 解释: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 * 
 */
// 快乐数的规律：4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4
bool isHappy(int n)
{
    int sum = 0;
    int tmp;
    while (n)
    {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    //printf("%d\n", sum);
    if (sum == 4)
    {
        return false;
    }
    if (sum == 1)
    {
        return true;
    }
    else
    {
        return isHappy(sum);
    }
}
