#
# @lc app=leetcode.cn id=788 lang=python
#
# [788] Rotated Digits
#
# https://leetcode-cn.com/problems/rotated-digits/description/
#
# algorithms
# Easy (52.32%)
# Total Accepted:    3.1K
# Total Submissions: 6K
# Testcase Example:  '10'
#
# 我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
# 
# 如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和 9
# 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
# 
# 现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
# 
# 
# 示例:
# 输入: 10
# 输出: 4
# 解释: 
# 在[1, 10]中有四个好数： 2, 5, 6, 9。
# 注意 1 和 10 不是好数, 因为他们在旋转之后不变。
# 
# 
# 注意:
# 
# 
# N 的取值范围是 [1, 10000]。
# 
# 
#
class Solution(object):
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        reversetable1 = {}        
        reversetable2 = {}

        reversetable1['0'] = 0
        reversetable1['1'] = 1
        reversetable1['8'] = 8
        reversetable2['2'] = 5
        reversetable2['5'] = 2
        reversetable2['6'] = 9
        reversetable2['9'] = 6
        # print(reversetable2.keys())
        count = 0
        for i in range(1, N+1):
            flag = 0
            for ch in str(i):
                if ch not in reversetable1.keys() and ch not in reversetable2.keys():
                    flag = 0
                    break
                if ch in reversetable2.keys():
                    flag=1
            if flag:
                count += 1
        return count
        
        

