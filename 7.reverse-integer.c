/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (31.31%)
 * Total Accepted:    77.2K
 * Total Submissions: 246.6K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 * 
 */
int reverse(int x) {
    int sum = 0;
    while(x != 0)
    {
        int tmp = x % 10;
        
        if (sum > 2147483647/10 || (sum == 2147483647 / 10 && tmp > 7)) return 0;
        if (sum < -2147483648/10 || (sum == -2147483648 / 10 && tmp < -8)) return 0;
        sum = 10*sum + tmp;
        x = x / 10;
        
    }
    return sum;
}
