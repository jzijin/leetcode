/*
 * @lc app=leetcode.cn id=389 lang=c
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (54.13%)
 * Total Accepted:    6.3K
 * Total Submissions: 11.7K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * s = "abcd"
 * t = "abcde"
 * 
 * 输出：
 * e
 * 
 * 解释：
 * 'e' 是那个被添加的字母。
 * 
 * 
 */
char findTheDifference(char* s, char* t) {
    char result = 0x00;
    while(*s) {
        result ^= *s++;
    }
    while(*t) {
        result ^= *t++;
    }
    return result;
}

