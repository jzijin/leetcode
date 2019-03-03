/*
 * @lc app=leetcode.cn id=387 lang=c
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (35.57%)
 * Total Accepted:    20.5K
 * Total Submissions: 57.7K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */
int firstUniqChar(char* s) {
    int target[26] = {0};
    int s_length = strlen(s);
    // if(s_length <= 0)
    // {
    //     return -1;
    // }
    int index;
    int i;
    for(i=0; i<s_length; i++)
    {
        index = (int)(s[i] - 'a');
        // printf("%d\n", index);
        target[index] += 1;
    }
    for(i=0; i<s_length; i++)
    {
        index = (int)(s[i] - 'a');
        if(target[index] == 1)
        {
            return i;
        }
    }
    return -1;
}

