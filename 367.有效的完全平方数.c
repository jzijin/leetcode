/*
 * @lc app=leetcode.cn id=367 lang=c
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (39.65%)
 * Total Accepted:    6.1K
 * Total Submissions: 15.5K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */
bool isPerfectSquare(int num)
{
    // printf("%f\n", sqrt(2147483647));
    if (num == 1)
    {
        return true;
    }
    if (num < 1 || num < 4)
    {
        return false;
    }
    int tmp = num / 2;
    if (tmp > 46340)
    {
        tmp = 46340;
    }

    // 应该还有一个对半查找可以省一半的时间
    for (int i = 1; i <= tmp; i++)
    {
        if (i * i == num)
        {
            return true;
        }
    }
    return false;

    /*
    if(num <= 0) 
            return false;
        if(num == 1) 
            return true;
        long l=1, r = num/2; 
        long mid, midSq;
        while(l <= r){
            mid = (l + r)/2;
            midSq = mid * mid;
            if(midSq == num) return true;
            if(midSq < num) l = mid+1;
            else r = mid-1;
        }
        return false;
        */
}
