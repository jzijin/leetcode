/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (45.91%)
 * Total Accepted:    15.4K
 * Total Submissions: 33.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
char *addBinary(char *a, char *b)
{
    int a_length = strlen(a);
    int b_length = strlen(b);
    int max_length = a_length > b_length ? a_length : b_length;

    // 先比目标长度多开辟两个空间 一个用来放 '\0' 另一个用来放进位 
    int target_length = max_length + 2;
    char *target = (char *)malloc(sizeof(char) * (target_length));
    target[target_length - 1] = '\0'; // 记得去尾工作
    target[0] = '0';
    a_length -= 1; // 得到index 比长度少1 从0开始
    b_length -= 1;
    int jinwei = 0;
    int sum = 0;
    while (1)
    {
        if (a_length < 0 && b_length < 0)
        {
            break;
        }
        if (a_length < 0 && b_length >= 0)
        {
            // 注意把字符转化为整数
            sum = (int)(b[b_length] - '0') + jinwei;
        }
        else if (a_length >= 0 && b_length < 0)
        {
            sum = (int)(a[a_length] - '0') + jinwei;
        }
        else
        {
            sum = (int)(b[b_length] - '0') + (int)(a[a_length] - '0') + jinwei;
        }

        if (sum == 2)
        {
            // 把整数转化尾字符
            target[max_length] = (char)(0 + '0');
            jinwei = 1;
        }
        else if (sum == 3)
        {
            
            target[max_length] = (char)(1 + '0');
            jinwei = 1;
        }
        else
        {
            target[max_length] = (char)(sum + '0');
            jinwei = 0; // 重置进位为0
        }

        a_length--;
        b_length--;
        max_length--;
    }
    target[max_length] = (char)(jinwei + '0');

    // 如果最高位没有产生进位 把最初的一位去掉
    if (target[0] == '0')
    {
        char *new_target = (char *)malloc(sizeof(char) * (target_length - 1));
        new_target[target_length - 2] = '\0';
        for (int i = 0; i < target_length - 2; i++)
        {
            new_target[i] = (char)target[i + 1];
        }
        return new_target;
    }
    return target;
}