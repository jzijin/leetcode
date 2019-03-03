/*
 * @lc app=leetcode.cn id=415 lang=c
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (43.05%)
 * Total Accepted:    4.7K
 * Total Submissions: 10.9K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */
/*

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        if len(num1) > len(num2):
            for i in range(len(num1)-len(num2)):
                num2 = '0' + num2
        else:
            for i in range(len(num2)-len(num1)):
                num1 = '0' + num1
        
        
        jinwei = 0
        length = len(num1)
        print(length)
        print(num1)
        tmp = 0
        res = ""
        while(length > 0):
            tmp = int(num1[length-1]) + int(num2[length-1]) + jinwei
            if tmp >= 10:
                res = str(tmp-10) + res;
                jinwei = 1
            else:
                res = str(tmp) + res;
                jinwei = 0;
            length = length - 1;
        if jinwei == 1:
            res = '1' + res
        
        
        return res
            
        
#         int n1_length = strlen(num1);
#     int n2_length = strlen(num2);
#     if(n1_length > n2_length)
#     {
#         for(int i=0; i<n1_length-n2_length; i++)
#         {
            
#         }
#     }
#     int length = n1_length > n2_length ? n2_length:n1_length;
    
    
    
#     int offset = 0;
            
            */
char* addStrings(char* num1, char* num2) {
    int n1_length = strlen(num1);
    int n2_length = strlen(num2);
    if(n1_length > n2_length)
    {
        while
    }
}

