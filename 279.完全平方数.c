/*
 * @lc app=leetcode.cn id=279 lang=c
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (47.30%)
 * Total Accepted:    6.3K
 * Total Submissions: 13.1K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */
// TODO: 如何快速理解 找到转移方程 很关键！！！
int isquare(int num)
{
    if (sqrt(num) == (int)sqrt(num))
    {
        return 1;
    }
    return 0;
}
int numSquares(int n) {
    // 尝试用动态规划的方式做
    int *dp = (int *)malloc(sizeof(int)*(n+1));
    dp[0] = 0;
    for(int i=1; i<n+1; i++)
    {
        dp[i] = 2147483647;
        for(int j=1; j*j<=i; j++)
        {
            dp[i] = dp[i] < dp[i-j*j] + 1 ? dp[i] : dp[i-j*j] + 1;
        }
    }
    return dp[n];
}
/* 四平方定理？？？？ 一脸懵逼！！！！！
int numSquares(int n) {
    //先根据上面提到的公式来缩小n
    while(n % 4 == 0) {
        n /= 4;
    }
    //如果满足公式 则返回4
    if(n % 8 == 7) {
        return 4;
    }
    //在判断缩小后的数是否可以由一个数的平方或者两个数平方的和组成
    int a = 0;
    while ((a * a) <= n) {
        int b = sqrt((n - a * a));
        if(a * a + b * b == n) {
            //如果可以 在这里返回
            if(a != 0 && b != 0) {
                return 2;
            } else{
                return 1;
            }
        }
        a++;
    }
    //如果不行 返回3
    return 3;
}
*/

