/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.55%)
 * Total Accepted:    47.7K
 * Total Submissions: 151.2K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
char *longestCommonPrefix(char **strs, int strsSize)
{
    int i, j, index;
    if (strsSize == 0)
    {
        return "";
    }
    if (strsSize == 1)
    {
        return *strs;
    }
    int last = 0;
    int flag = 1;
    for (i = 0; i < strsSize - 1; i++)
    {
        if (*(*(strs + i)) == '\0' || *(*(strs + i + 1)) == '\0')
        {
            return "";
        }
        index = 0;
        int l = 0;
        while (1)
        {
            // 如果两个比较字符串一样长的话 需要这个判断
            if(*(*(strs + i) + l) == '\0' || *(*(strs + i + 1) + l) == '\0')
            {
                break;
            }
            if (*(*(strs + i) + l) != *(*(strs + i + 1) + l))
            {
                break;
            }
            if (*(*(strs + i) + l) == *(*(strs + i + 1) + l))
            {
                index++;
            }
            l++;
        }
        
        // flag 作用第一次给last赋值 
        if (flag)
        {
            last = index;
            // 重置成0 只需要赋值一次就可以了
            flag = 0;
        }
        if (last > index)
        {
            last = index;
        }
    }
    if (!last)
    {
        return "";
    }
    char *target = (char *)malloc(sizeof(char) * (last + 1));
    for (j = 0; j < last; j++)
    {
        target[j] = *(*strs + j);
    }
    // 补充末尾的结束符
    target[last] = '\0';
    return target;
}
