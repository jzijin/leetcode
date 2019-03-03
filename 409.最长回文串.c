/*
 * @lc app=leetcode.cn id=409 lang=c
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (45.88%)
 * Total Accepted:    3.5K
 * Total Submissions: 7.6K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */
int longestPalindrome(char* s) {
    int *flag = (int*)malloc(sizeof(int)*128);
    memset(flag,0,128*4);
    int s_length = strlen(s);
    for(int i=0; i<s_length; i++)
    {
        int index = (int)(s[i]);
        // printf("%d\n", index);
        flag[index]++;
        // printf("%d\n", flag[index]);
    } 
    int count1=0;
    int count2=0;
    int f = 0;
    for(int i=0; i<128; i++)
    {
        if(flag[i] >= 2)
        {
            if(flag[i]%2)
            {
                f=1;
            }
            count1 += flag[i] /2;
            
        }
        if(flag[i] == 1)
        {
            count2++;
        }
    }
    printf("%d\n%d\n", count1,count2);
    count2 = count2 > 0 || f ? 1:0;
    return count1*2 + count2;
}

