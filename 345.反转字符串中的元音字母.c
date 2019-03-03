/*
 * @lc app=leetcode.cn id=345 lang=c
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (45.96%)
 * Total Accepted:    6.4K
 * Total Submissions: 13.9K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */
bool isYuanyin(char a)
{
    if(a == 'a' || a == 'A' || a == 'e' || a== 'E' || a=='i' || a=='I' || a== 'o' || a=='O'||a=='u' || a=='U')
    {
        return true;
    }
    return false;
}
char* reverseVowels(char* s) {
    int start = 0;
    int end = strlen(s) - 1;
    while(start < end)
    {
        if(!isYuanyin(s[start]))
        {
            start++;
        }
        if(!isYuanyin(s[end]))
        {
            end--;
        }
        if(isYuanyin(s[start]) && isYuanyin(s[end]))
        {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }
    return s;
}

