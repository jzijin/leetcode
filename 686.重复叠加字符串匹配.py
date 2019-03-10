#
# @lc app=leetcode.cn id=686 lang=python
#
# [686] 重复叠加字符串匹配
#
# https://leetcode-cn.com/problems/repeated-string-match/description/
#
# algorithms
# Easy (26.83%)
# Total Accepted:    2.1K
# Total Submissions: 7.6K
# Testcase Example:  '"abcd"\n"cdabcdab"'
#
# 给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。
# 
# 举个例子，A = "abcd"，B = "cdabcdab"。
# 
# 答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B 并不是其子串。
# 
# 注意:
# 
# A 与 B 字符串的长度在1和10000区间范围内。
# 
#
#TODO:有时间的话可以用微信公众号做一下题解
class Solution(object):
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """
        # 关键在于结束位置的判断
        length = len(A+A+B)
        i = 1
        while True:
            # print(A*i)
            if B in A*i:
                return i
            if len(A*i) >= length:
                break
            i+=1
        return -1
        # print("abc" in "abccdsss")
        

