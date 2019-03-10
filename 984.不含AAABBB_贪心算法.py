class Solution(object):
    def strWithout3a3b(self, A, B):
        ans = []

        while A or B:
            if len(ans) >= 2 and ans[-1] == ans[-2]:
                writeA = ans[-1] == 'b' # 计算一下是否应该写A
            else:
                writeA = A >= B    # 如果末尾两字符不相等 那么想在应该写入较长的哪个字符！！！！！！

            if writeA:
                A -= 1
                ans.append('a')
            else:
                B -= 1
                ans.append('b')

        return "".join(ans)