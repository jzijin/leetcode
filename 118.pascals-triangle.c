/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (59.22%)
 * Total Accepted:    15.7K
 * Total Submissions: 26.3K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int **columnSizes)
{
    // 先开辟二维数组的空间
    int **array = (int **)malloc(sizeof(int *) * numRows);
    *columnSizes = (int *)malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++)
    {
        (*columnSizes)[i] = i + 1;
        array[i] = (int *)malloc(sizeof(int) * (i + 1));
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                array[i][j] = 1;
            }
            else
            {
                array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
            }
        }
    }
    return array;
}
