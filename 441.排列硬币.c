/*
 * @lc app=leetcode.cn id=441 lang=c
 *
 * [441] 排列硬币
 *
 * https://leetcode-cn.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (35.36%)
 * Total Accepted:    4.8K
 * Total Submissions: 13.6K
 * Testcase Example:  '5'
 *
 * 你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
 * 
 * 给定一个数字 n，找出可形成完整阶梯行的总行数。
 * 
 * n 是一个非负整数，并且在32位有符号整型的范围内。
 * 
 * 示例 1:
 * 
 * 
 * n = 5
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * 
 * 因为第三行不完整，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * n = 8
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * 
 * 因为第四行不完整，所以返回3.
 * 
 * 
 */

int arrangeCoins(int n) {
   
    int ret = 0;
    for(int i=1; i<=n; i++)
    {
        n -= i; // 注意逆向思维 有时可以用减法来代替加法防止数值的溢出！！！！
        // 此题还可以用二分查找来求解！
        if(n >= 0)
        {
            ret++;
        }
        else
        {
            return ret;
        }
    }
    return ret;
    // return (int(sqrt(8*n+1))-1)/2; ？？？？？？ n*(n-1)/2 = target 数学计算配方得到
}

