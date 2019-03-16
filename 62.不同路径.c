/*
 * @lc app=leetcode.cn id=62 lang=c
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (52.64%)
 * Total Accepted:    14.8K
 * Total Submissions: 28K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 */
int getnum(int num, int time)
{
    int sum1 = time;
    int sum2 = 1;
    while(num > time)
    {
        sum1 *= num;
        num--;
    }
    while(time > 1)
    {
        sum2 *= time;
        time--;
    }
    return sum1/sum2;
}
// int uniquePaths(int m, int n) {
//     int num = m+n-2;
//     return getnum(num, n);
// }
// 不要用组合数的想法 应该用动态规划的想法做
int uniquePaths(int m, int n) {
    // int *col = (int *)malloc(sizeof(int)*n);// 有点类似杨辉三角哦！！！！！！
    // TODO: 其实动态规划问题的关键就是如何得到那个 关系式！！！！！
    int **target = (int **)malloc(sizeof(int **)*m);
    for(int i=0; i<m; i++)
    {
        target[i] = (int *)malloc(sizeof(int *)*n);
        for(int j=0; j<n; j++)
        {
            if(i==0|| j==0)
            {
                target[i][j] = 1;
            }
            else
            {
                target[i][j] = target[i-1][j] + target[i][j-1];
            }
        }
    }
    return target[m-1][n-1];
}

