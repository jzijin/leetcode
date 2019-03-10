/*
 * @lc app=leetcode.cn id=645 lang=c
 *
 * [645] 错误的集合
 *
 * https://leetcode-cn.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (33.93%)
 * Total Accepted:    2.6K
 * Total Submissions: 7.7K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 集合 S 包含从1到 n
 * 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
 * 
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,2,4]
 * 输出: [2,3]
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数组的长度范围是 [2, 10000]。
 * 给定的数组是无序的。
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 还是有点复杂 实际上可以更加精简一点 求一下1-numsSize 的和 求一下现在数组的和 在求一下去掉重复项的和
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    // 找到相同的值和最大值
    int max_num = 0;
    int thesame = 0;
    int flag = 0;
    int total = 0;
    for(int i=0; i<numsSize-1; i++)
    {
        max_num = nums[i] > max_num ? nums[i] : max_num;
        total += nums[i];
        for (int j=i+1; j<numsSize; j++)
        {
            if(flag)
            {
                break;
            }
            if(nums[i] == nums[j])
            {
                thesame = nums[i];
                flag = 1;
            }
        }
    }
    max_num = nums[numsSize-1] > max_num ? nums[numsSize-1] : max_num;
    total += nums[numsSize-1];
    // 把从1-n得数起来减去 数组求和-thesame 如果差为正数那么缺少的就是那个数 如果差值是零那么缺少的是最大数加1
    int logical = ((1+max_num)*max_num)/2;
    // printf("thesame=%d max_num=%d logical=%d total=%d" , thesame, max_num, logical, total);
    int target = logical-(total-thesame);
    // printf("%d\n", target);
    target = target>0?target:max_num+1;
    
    int *res = (int *)malloc(sizeof(int)*2);
    *returnSize = 2;
    res[0] = thesame;
    res[1] = target;
    
    
    // printf("thesame=%d max_num=%d", thesame, max_num);
    // int a[1];
    // a[0] = 1;
    return res;
}

