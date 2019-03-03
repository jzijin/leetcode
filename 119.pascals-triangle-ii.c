/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (53.33%)
 * Total Accepted:    9.5K
 * Total Submissions: 17.7K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */


// 实际上就是求组合数
// 但是效率不高 涉及浮点数 数字不准确
/*
double getNum(int n)
{
    double sum = 1;
    while(n)
    {
        sum *= n;
        n--;
    }
    return sum;

}
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* array = (int *)malloc(sizeof(int) * (*returnSize));
    for(int i=0; i<= rowIndex; i++)
    {
        array[i] = getNum(rowIndex) / (getNum(i)*getNum(rowIndex-i));
    }
    return array;
}
*/

// 求排列组合可以转化为求 杨辉三角！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
int *getRow(int rowIndex, int *returnSize)
{
    *returnSize = rowIndex + 1;
    int *num = (int *)malloc((rowIndex + 1) * sizeof(int));
    for (int i = 0; i <= rowIndex; i++)
        for (int j = i; j >= 0; j--)
        {
            if (j == 0 || j == i)
                num[j] = 1;
            else
                num[j] = num[j] + num[j - 1];
        }
    return num;
}
