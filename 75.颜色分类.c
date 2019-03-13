/*
 * @lc app=leetcode.cn id=75 lang=c
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (51.48%)
 * Total Accepted:    13.8K
 * Total Submissions: 26.8K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */
void sortColors(int *nums, int numsSize)
{
    // int * target = (int *)malloc(sizeof(int)*numsSize);
    // memset(target, 1, sizeof(int)*numsSize);
    // for(int i=0; i<numsSize; i++)
    // {
    //     target[i] = 1;
    // }
    // int start = 0;
    // int end = numsSize-1;
    // for(int i=0; i<numsSize; i++)
    // {
    //     if(nums[i] == 0)
    //     {
    //         target[start++] = 0;
    //     }
    //     else if(nums[i] == 2)
    //     {
    //         target[end--] = 2;
    //     }
    // }
    // // nums = target;
    // for(int i=0; i<numsSize; i++)
    // {
    //     // printf("%d ", target[i]);
    //     nums[i] = target[i];
    // }
    // return target;


    // 三路快排！！！！
    int start = -1;
    int end = numsSize;
    int tmp;
    for (int i = 0; i < end;)
    {
        if (nums[i] == 1)
        {
            i++;
        }
        else if (nums[i] == 2)
        {
            end--; // 如果等于2 把2移动到最末尾 就不用循环最后一个了
            tmp = nums[i];
            nums[i] = nums[end];
            nums[end] = tmp;

            // i++;
        }
        else
        {
            start++;
            tmp = nums[i];
            nums[i] = nums[start];
            nums[start] = tmp;
            i++;
        }
    }
}
