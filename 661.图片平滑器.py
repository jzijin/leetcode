#
# @lc app=leetcode.cn id=661 lang=python
#
# [661] 图片平滑器
#
# https://leetcode-cn.com/problems/image-smoother/description/
#
# algorithms
# Easy (45.07%)
# Total Accepted:    2K
# Total Submissions: 4.5K
# Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
#
# 包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入)
# ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。
# 
# 示例 1:
# 
# 
# 输入:
# [[1,1,1],
# ⁠[1,0,1],
# ⁠[1,1,1]]
# 输出:
# [[0, 0, 0],
# ⁠[0, 0, 0],
# ⁠[0, 0, 0]]
# 解释:
# 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
# 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
# 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
# 
# 
# 注意:
# 
# 
# 给定矩阵中的整数范围为 [0, 255]。
# 矩阵的长和宽的范围均为 [1, 150]。
# 
# 
#
# class Solution(object):
#     def calculate(self, M, i, j):
#         row = len(M)
#         col = len(M[0])
        
#         total = 0;
#         total += M[i][j]
#         index = 1
#         if i+1 < row-1:
#             total += M[i+1][j]
#             index += 1
#         if i-1 >= 0:
#             total += M[i-1][j]
#             index += 1
#         if j+1 < col-1:
#             total += M[i][j+1]
#             index += 1
#         if j-1 >= 0:
#             total += M[i][j-1]
#             index += 1
#         if i+1<row-1 and j+1 < col-1:
#             total += M[i+1][j+1]
#             index += 1
#         if i+1<row-1 and j-1 >= 0:
#             total += M[i+1][j-1]
#             index += 1
#         if i-1>=0 and j+1 < col-1:
#             total += M[i-1][j+1]
#             index += 1
#         if i-1>=0 and j-1 >= 0:
#             total += M[i-1][j-1]
#             index += 1
#         # total += M[i][j]
#         return total/index
            
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        N = [[0 for i in j] for j in M]
        d = [(-1,-1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)]
        
        for x in range(len(M)):
            for y in range(len(M[0])):
                
                num = 0
                sum = 0
                for k in d:
                    xi, yi = x + k[0], y + k[1]
                    if 0 <= xi < len(M) and 0 <= yi < len(M[0]):
                        sum += M[xi][yi]
                        num += 1
                N[x][y] = sum // num
        return N
        
        
        

