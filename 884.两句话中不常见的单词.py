# class Solution(object):
#     def uncommonFromSentences(self, A, B):
#         """
#         :type A: str
#         :type B: str
#         :rtype: List[str]
#         """
#         A = A.split()
#         B = B.split()
#         # print(A, B)
#         a_map = {}
#         for i in A:
#             if i in a_map.keys():
#                 a_map[i] += 1
#             else:
#                 a_map[i] = 1
#         b_map = {}
#         for i in B:
#             if i in b_map.keys():
#                 b_map[i] += 1
#             else:
#                 b_map[i] = 1
        
#         target = []
#         for i in a_map.keys():
#             if a_map[i] == 1 and i not in b_map.keys():
#                 target.append(i)
#         for i in b_map.keys():
#             if b_map[i] == 1 and i not in a_map.keys():
#                 target.append(i)
#         return target
class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        # 理解为 将 两个字符串加起来 只出现过一次 那么就是不常见的单词 应该返回
        A = A + ' ' + B
        A = A.split()
        a_map = {}
        for i in A:
            if i in a_map.keys():
                a_map[i] += 1
            else:
                a_map[i] = 1
        target = []
        for i in a_map.keys():
            if a_map[i] == 1:
                target.append(i)
        return target
        
        