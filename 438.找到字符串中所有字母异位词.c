/*
 * @lc app=leetcode.cn id=438 lang=c
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Easy (35.29%)
 * Total Accepted:    3.2K
 * Total Submissions: 9K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 * 
 * 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
 * 
 * 说明：
 * 
 * 
 * 字母异位词指字母相同，但排列不同的字符串。
 * 不考虑答案输出的顺序。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s: "cbaebabacd" p: "abc"
 * 
 * 输出:
 * [0, 6]
 * 
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s: "abab" p: "ab"
 * 
 * 输出:
 * [0, 1, 2]
 * 
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 双指针 加 滑动窗口！！！！！
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int s_length = strlen(s);
    int p_length = strlen(p);
    int *tmp = (int *)malloc(sizeof(int)*(s_length));
    int l = 0;
    int p_map[128] = {0};
    for(int i=0; i<p_length; i++)
    {
        p_map[p[i]]++;
    }
    
    
    int count = p_length;
    int lo = 0, hi=0;
    while(hi<s_length)
    {
        if(p_map[s[hi]]-- >= 1 )
        {
            // p_map[s[hi]]--;
            count--;
        }
        hi++;
        if(count == 0)
        {
            tmp[l++] = lo;
        }
        
        // 移动窗口
        if(hi-lo == p_length)
        {
            if(p_map[s[lo]]++ >= 0)
            {
                // p_map[s[lo]]++;
                count++;
            }
            lo++;
        }
        
    }
    
    
    
    
    
    
    
//     int *tmp = (int *)malloc(sizeof(int)*(s_length));
//     int l = 0;
//     for(int i=0; i<s_length-p_length+1; i++)
//     {
//         int flag = 0;
//         int index = i;
//         for(int j=0; j<p_length; j++)
//         {       
//             // printf("%d\n", (int)p[j]);
//             flag ^= (int)p[j];
//             flag ^= (int)s[index++];            
//             // index++;            
//         }
//         printf("%d\n", flag);
//         if(flag == 0)
//         {
//             tmp[l++] = i;
//         }
        
//     }
    int *target = (int *)malloc(sizeof(int)*l);
    *returnSize = l;
    for(int i=0; i<l; i++)
    {
        target[i] = tmp[i];
    }
    return target;
    // return 1;
}

