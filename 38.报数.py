#
# @lc app=leetcode.cn id=38 lang=python
#
# [38] 报数
#
# https://leetcode-cn.com/problems/count-and-say/description/
#
# algorithms
# Easy (48.12%)
# Total Accepted:    22.3K
# Total Submissions: 46.1K
# Testcase Example:  '1'
#
# 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
# 
# 1.     1
# 2.     11
# 3.     21
# 4.     1211
# 5.     111221
# 
# 
# 1 被读作  "one 1"  ("一个一") , 即 11。
# 11 被读作 "two 1s" ("两个一"）, 即 21。
# 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
# 
# 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
# 
# 注意：整数顺序将表示为一个字符串。
# 
# 
# 
# 示例 1:
# 
# 输入: 1
# 输出: "1"
# 
# 
# 示例 2:
# 
# 输入: 4
# 输出: "1211"
# 
# 
#

# TODO: 递归的思想啊！！！！！！！！
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        
        def count(n, str_num):
            if n <= 1:
                return str_num
            new_str_num = ""
            cnt, old = 1, str_num[0]
            for ch in str_num[1:]:
                if ch != old:
                    new_str_num += str(cnt) + old
                    cnt, old = 1, ch
                else:
                    cnt += 1
            if cnt:
                new_str_num += str(cnt) + str_num[-1]
            return count(n-1, new_str_num)
        return count(n, "1")
            
            
        
        

