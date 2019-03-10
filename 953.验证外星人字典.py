class Solution(object):
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        # 先用字典建立hashmap 来为判断顺序做匹配
        dic = {}
        for ch in range(0, len(order)):
            dic[order[ch]] = ch
        
        for i in range(1, len(words)):
            # 用最短的字符长度去循环
            length = min(len(words[i-1]), len(words[i]))
            flag = 1
            for j in range(0, length):
                if dic[words[i-1][j]] < dic[words[i][j]]:
                    # 如果已经满足 顺序 设置标志位 跳出循环
                    flag = 0
                    break
                elif dic[words[i-1][j]] > dic[words[i][j]]:
                    return False
            if flag:# 类似 app apple的比较
                if len(words[i-1]) > len(words[i]):
                    return False
        return True
        