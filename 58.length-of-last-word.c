/*
 * @lc app=leetcode.cn id=58 lang=c
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (28.51%)
 * Total Accepted:    16.3K
 * Total Submissions: 57.3K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */
int lengthOfLastWord(char *s)
{
    int length = strlen(s);
    if (length == 0)
    {
        return 0;
    }
    int m = (length + 1) / 2;
    int index = 0;
    // 翻转字符串
    for (int i = 0; i < m; i++)
    {
        int j = length - 1 - i;
        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    // 去掉 空格
    while (1)
    {
        if (*s == ' ')
        {
            s += 1;
        }
        else
        {
            break;
        }
        // 都是空格 无单词
        if (*s == '\0')
        {
            return 0;
        }
    }
    while (1)
    {
        if (*s == ' ' || *s == '\0')
        {
            break;
        }
        index++;
        s += 1;
    }
    return index;
}

/*
// 注意不能导致越界
int lengthOfLastWord(char *s)
{
    int length = strlen(s);
    if (length == 0)
    {
        return 0;
    }
    int max_num = length - 1;
    while (1)
    {
        if (max_num == -1)
        {
            break;
        }
        if (s[max_num] == ' ')
        {
            max_num--;
        }
        else
        {
            break;
        }
    }
    int index = 0;
    while (1)
    {
        if (max_num == -1 || s[max_num] == ' ')
        {
            break;
        }
        else
        {
            max_num--;
            index++;
        }
    }
    return index;
}
*/
