/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (42.31%)
 * Total Accepted:    6.7K
 * Total Submissions: 15.8K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */
bool isIsomorphic(char *s, char *t)
{
    int s_length = strlen(s);
    int t_length = strlen(t);
    if (s_length == 0 && t_length == 0)
    {
        return true;
    }
    if (s_length != t_length)
    {
        return false;
    }
    int ft[128] = {0};
    int fs[128] = {0};
    for (int i = 0; i < s_length; i++)
    {
        // 如果为添加映射 就添加映射
        if (fs[s[i]] == 0 && ft[t[i]] == 0)
        {
            fs[s[i]] = t[i];
            ft[t[i]] = s[i];
        }
        // 两字符相同 第二次进来 已经添加完映射了 判断映射值 是否和准备映射值相同
        else if (fs[s[i]] != t[i] || ft[t[i]] != s[i])
        {
            return false;
        }
    }
    return true;

    // 太慢
    // for(int i=1; i<s_length; i++)
    // {
    //     for(int j=0; j<i; j++)
    //     {
    //         if((s[i] == s[j] && t[i] != t[j]) || (t[i] == t[j] && s[i] != s[j]))
    //         {
    //             return false;
    //         }
    //     }
    // }
}
