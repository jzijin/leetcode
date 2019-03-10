#
# @lc app=leetcode.cn id=844 lang=python
#
# [844] Backspace String Compare
#
# https://leetcode-cn.com/problems/backspace-string-compare/description/
#
# algorithms
# Easy (45.48%)
# Total Accepted:    4.3K
# Total Submissions: 9.4K
# Testcase Example:  '"ab#c"\n"ad#c"'
#
# 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
# 
# 
# 
# 示例 1：
# 
# 输入：S = "ab#c", T = "ad#c"
# 输出：true
# 解释：S 和 T 都会变成 “ac”。
# 
# 
# 示例 2：
# 
# 输入：S = "ab##", T = "c#d#"
# 输出：true
# 解释：S 和 T 都会变成 “”。
# 
# 
# 示例 3：
# 
# 输入：S = "a##c", T = "#a#c"
# 输出：true
# 解释：S 和 T 都会变成 “c”。
# 
# 
# 示例 4：
# 
# 输入：S = "a#c", T = "b"
# 输出：false
# 解释：S 会变成 “c”，但 T 仍然是 “b”。
# 
# 
# 
# 提示：
# 
# 
# 1 <= S.length <= 200
# 1 <= T.length <= 200
# S 和 T 只含有小写字母以及字符 '#'。
# 
# 
# 
# 
#

# TODO: 主要是利用栈的思想来实现的
class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        str_list1 = []
        str_list2 = []
        i=0
        while i<len(S):
            if S[i] == '#' and len(str_list1) > 0:
                str_list1.pop()
                i += 1
            elif S[i] == '#' and len(str_list1) == 0:
                # str_list1.pop()
                i += 1
            else:
                str_list1.append(S[i])
                i += 1
            # print(str_list1)
        
        j=0
        while j<len(T):
            if T[j] == '#' and len(str_list2) > 0:
                str_list2.pop()
                j += 1
            elif T[j] == '#' and len(str_list2) == 0:
                # str_list1.pop()
                j += 1
            else:
                str_list2.append(T[j])
                j += 1
            # print(str_list2)
        # print(str_list1)        
        # print(str_list2)
        str1 = ''.join(str_list1)
        str2 = ''.join(str_list2)
        print(str1, str2)
        if str1 == str2:
            return True
        return False

                

