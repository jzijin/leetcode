/*
 * @lc app=leetcode.cn id=322 lang=c
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (29.21%)
 * Total Accepted:    6.4K
 * Total Submissions: 21.8K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */
// TODO: 值得深思啊 如何才能快速的找到转移方程呢？？？？？
// 【PHP解法==LeetCode（动态规划4-（背包问题））】416.分割等和子集 && 322.零钱兑换 && 377.组合总和 && 474.一和零 && 139.单词拆分 && 494.目标和 如何解决呢？？？？？
int coinChange(int* coins, int coinsSize, int amount) {
    
    if(coinsSize <= 0)
        return -1;
    
    int * dp = (int *)malloc(sizeof(int)*(amount+1));
    dp[0] = 0;
    for(int i=1; i<=amount; i++)
    {
        dp[i] = 2147483647;
        for(int j=0; j<coinsSize; j++)
        {
            if(i-coins[j] >= 0)
            {
                dp[i] = dp[i] < dp[i-coins[j]] + 1 ? dp[i] :dp[i-coins[j]] + 1;
            }
        }
        
    }
    if(dp[amount] == 2147483647)
        return -1;
    return dp[amount];
}

