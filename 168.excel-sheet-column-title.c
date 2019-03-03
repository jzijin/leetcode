/*
 * @lc app=leetcode.cn id=168 lang=c
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (29.63%)
 * Total Accepted:    5K
 * Total Submissions: 16.7K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */
char *convertToTitle(int n)
{
    if (n == 0)
    {
        return "";
    }
    // 本质上是26进制；
    // 放结束符的
    char *return_chars = (char *)malloc(sizeof(char) * 100);

    //int tmp;
    int index = 0;
    while (n)
    {

        return_chars[index] = (char)((n - 1) % 26 + 65);

        index++;
        n = (n - 1) / 26;
    }
    //return_chars[index] = (char)(n + 64);
    return_chars[index] = '\0';
    int length = strlen(return_chars);
    for (int i = 0; i < length; i++, length--)
    {
        int tmp = return_chars[i];
        return_chars[i] = return_chars[length - 1];
        return_chars[length - 1] = tmp;
    }
    return return_chars;
}