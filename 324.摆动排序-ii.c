/*
 * @lc app=leetcode.cn id=324 lang=c
 *
 * [324] 摆动排序 II
 *
 * https://leetcode-cn.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (28.52%)
 * Total Accepted:    1.3K
 * Total Submissions: 4.6K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * 给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1, 5, 1, 1, 6, 4]
 * 输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
 * 
 * 示例 2:
 * 
 * 输入: nums = [1, 3, 2, 2, 3, 1]
 * 输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
 * 
 * 说明:
 * 你可以假设所有输入都会得到有效的结果。
 * 
 * 进阶:
 * 你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
 * 
 */
void quicksort(int *nums, int start, int end)
{
    if(start > end)
    {
        return;
    }
    int i,j, temp;
    i = start;
    j = end;
    temp = nums[start];
    while(i!=j)
    {
        while(i<j&&nums[j] >= temp)
        {
            j--;
        }
        while(i<j&&nums[i] <= temp)
        {
            i++;
        }
        if(i<j)
        {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        
    }
    nums[start] = nums[i];
    nums[i] = temp;
    quicksort(nums, start, i-1);
    quicksort(nums, i+1, end);
}
// TODO: 时间复杂度 nlogn 空间负责度 n 感觉没有满足 题目的意思 
// 主要思路是先快速排序 在插值降序
void wiggleSort(int* nums, int numsSize) {
    // int tmp;
    // for(int i=0; i<numsSize-1; i++)
    // {
    //     for(int j=0; j<numsSize-1-i; j++)
    //     {
    //         if (nums[j] > nums[j+1])
    //         {
    //             tmp = nums[j];
    //             nums[j] = nums[j+1];
    //             nums[j+1] = tmp;
    //         }
    //     }
    // }
    // for(int i=0; i<numsSize; i++)
    // {
    //     printf("%d ", nums[i]);
    // }
    // 拷贝一份
    quicksort(nums, 0, numsSize-1);
    int* target = (int*)malloc(sizeof(int)*numsSize);
    memcpy(target, nums, sizeof(int)*numsSize);
    
    
    int flag=1;
    int index = 0;
    int min_ = (numsSize-1)/2;
    int max_ = numsSize-1;
    while(index < numsSize)
    {
        if(flag)
        {
            // 左半边赋值
            nums[index++] = target[min_--];
            flag = 0;
        }
        else
        {
            // 右半边赋值
            nums[index++] = target[max_--];
            flag=1;
        }
    }
    
    
}

