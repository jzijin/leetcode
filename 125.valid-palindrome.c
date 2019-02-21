/*
 * @lc app=leetcode.cn id=125 lang=c
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (37.64%)
 * Total Accepted:    21.9K
 * Total Submissions: 58.1K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
// 能否只用一个for循环来写呢？？？？
bool isPalindrome(char *s)
{
    int length = strlen(s);
    char *target = (char *)malloc(sizeof(char) * (length + 1));
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        // 0 的ascii码 是48；
        if (s[i] >= 48 && s[i] <= 57)
        {
            target[j] = s[i];
            j++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            target[j] = s[i] + 32;
            j++;
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            target[j] = s[i];
            j++;
        }
    }
    target[j] = '\0';
    int target_length = strlen(target);
    for (int i = 0; i < target_length; i++)
    {
        if (i >= length / 2)
        {
            break;
        }
        if (target[i] != target[target_length - i - 1])
        {
            return false;
        }
    }
    return true;
}
