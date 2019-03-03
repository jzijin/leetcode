/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (49.98%)
 * Total Accepted:    19.8K
 * Total Submissions: 39.6K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？！！！！
bool isAnagram(char* s, char* t) {
    int s_length = strlen(s);
    int t_length = strlen(t);
    if(s_length == 0 && t_length == 0)
    {
        return true;
    }
    if(s_length != t_length)
    {
        return false;
    }
    // 理论上只需要26个长度 可以把a-z 转化为 0-25
    int *fs = (int *)malloc(sizeof(int)*128);
    int *ft = (int *)malloc(sizeof(int)*128);
    memset(fs, 0, 128);    memset(ft, 0, 128);

    
    for(int i=0; i<s_length; i++)
    {
        fs[s[i]] += 1;
        ft[t[i]] += 1;
    }
    for(int i=0; i<128; i++)
    {
        if(fs[i] != ft[i])
        {
            return false;
        }
    }
    return true;
}
