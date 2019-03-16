/*
 * @lc app=leetcode.cn id=96 lang=c
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (57.68%)
 * Total Accepted:    5.5K
 * Total Submissions: 9.6K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */
int numTrees(int n) {
    //动态规划，把1到n中的每一个结点 i 轮流作为根结点，两边子树种类相乘就是 i 作为根节点的种类数
    if(n <= 1)
        return 1;
    int *dp = (int *)malloc(sizeof(int)*(n+1));
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n;i++)
    {
        dp[i] = 0;
        for(int j=0; j<=i-1; j++) // 左边j个结点， 右边i-1-j个结点
            dp[i] += dp[j]*dp[i-1-j];
    }
    return dp[n];
}

