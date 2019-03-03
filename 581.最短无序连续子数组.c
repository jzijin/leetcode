/*
 * @lc app=leetcode.cn id=581 lang=c
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (30.61%)
 * Total Accepted:    3K
 * Total Submissions: 9.9K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 
 */
int findUnsortedSubarray(int* nums, int numsSize) {
    int * bak = (int *)malloc(sizeof(int)*numsSize);
    memcpy(bak, nums, numsSize*sizeof(int));
    for(int i=0; i<numsSize-1; i++)
    {
        for(int j=i; j<numsSize;j++)
        {
            if(bak[i] > bak[j])
            {
                int temp = bak[i];
                bak[i] = bak[j];
                bak[j] = temp;
            }
        }
    }
    // int pre=0;
    // int last=0;
    // for(int i=0; i<numsSize; i++)
    // {
    //     // printf("%d\n", bak[i]);
    //     if(nums[i] != bak[i])
    //     {
    //         pre = i;
    //         break;
            
    //     }
    // }
    // for(int i=numsSize-1; i>=0; i--)
    // {
    //     // printf("%d\n", bak[i]);
    //     if(nums[i] != bak[i])
    //     {
    //         last = i;
    //         break;
            
    //     }
    // }
    int start = 0;
    int end = numsSize-1;
    while(start < end)
    {
         int flag = 1; //设置一个flag
            if(nums[start] == bak[start]){ start++; flag = 0;} //相等， i ++
            if(nums[end] == bak[end]){ end--; flag = 0;}//相等， j--
            if(flag == 1) break; //都不想等， 就break
    }
    if(start>=end)
    {
        return 0;
    }
    // printf("%d\nlast=%d\n", pre, last);
    
    return start-end+1;
}

