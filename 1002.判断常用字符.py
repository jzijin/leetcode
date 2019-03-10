class Solution(object):
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        res = []
        for i in A[0]: # 常用字符包含在第一个字符床中
            flag = 1
            for j in range(1, len(A)): # 判断i是否是常用字符
                if i not in A[j]:
                    flag = 0
                    break
            # 如果是常用字符， 则每个字符串都删掉一个常用字符
            if flag:
                res.append(i)
                for j in range(1,  len(A)):
                    index = A[j].find(i)
                    A[j] = A[j][:index] + A[j][index+1:]
        return res