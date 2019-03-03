/*
 * @lc app=leetcode.cn id=405 lang=c
 *
 * [405] 数字转换为十六进制数
 *
 * https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (44.11%)
 * Total Accepted:    2.2K
 * Total Submissions: 5.1K
 * Testcase Example:  '26'
 *
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 * 
 * 注意:
 * 
 * 
 * 十六进制中所有字母(a-f)都必须是小写。
 * 
 * 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
 * 给定的数确保在32位有符号整数范围内。
 * 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:
 * 26
 * 
 * 输出:
 * "1a"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入:
 * -1
 * 
 * 输出:
 * "ffffffff"
 * 
 * 
 */

int get_size(int num)
{
    int mask = 16;
    int size = 1;
    while(num &(mask-1) != num)
    {
        size++;
        mask *= 16;
        
    }
    return size;
}
char* toHex(int num) {
    char hex_char_map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    uint32_t u_num = num;
    int size = get_size(num);
    char *target = (char *)malloc(sizeof(char)*(size+1));
    target[size] = '\0';
    if (u_num == 0) {
        target[0] = hex_char_map[0];
        return target;
    }
    
    int index = size - 1;
    
    while(u_num > 0) {
        target[index] = hex_char_map[u_num & 15];
        u_num >>= 4;
        index--;
    }
    
    return target;
    
}

