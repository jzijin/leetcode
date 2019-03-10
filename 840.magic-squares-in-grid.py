#
# @lc app=leetcode.cn id=840 lang=python
#
# [840] Magic Squares In Grid
#
# https://leetcode-cn.com/problems/magic-squares-in-grid/description/
#
# algorithms
# Easy (30.72%)
# Total Accepted:    1.6K
# Total Submissions: 5.3K
# Testcase Example:  '[[4,3,8,4],[9,5,1,9],[2,7,6,2]]'
#
# 3 x 3 的幻方是一个填充有从 1 到 9 的不同数字的 3 x 3 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。
# 
# 给定一个由整数组成的 grid，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。
# 
# 
# 
# 示例：
# 
# 输入: [[4,3,8,4],
# ⁠     [9,5,1,9],
# ⁠     [2,7,6,2]]
# 输出: 1
# 解释: 
# 下面的子矩阵是一个 3 x 3 的幻方：
# 438
# 951
# 276
# 
# 而这一个不是：
# 384
# 519
# 762
# 
# 总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
# 
# 
# 提示:
# 
# 
# 1 <= grid.length <= 10
# 1 <= grid[0].length <= 10
# 0 <= grid[i][j] <= 15
# 
# 
#
class Solution(object):
    def check(self, grid):
        dic = {}
        for i in grid:
            for j in i:
                if j <= 0 or j>9:
                    return False
                if j in dic.keys():
                    dic[j] += 1
                else:
                    dic[j] = 1
                    
        for i in dic.values():
            if i > 1:
                return False
            
            
        for i in grid:
            if sum(i) != 15:
                return False
        for i in range(0,3):            
            tmp = 0
            for j in grid:
                tmp += j[i]
            if tmp != 15:
                return False
        if grid[0][0]+grid[1][1]+grid[2][2] != 15 or grid[0][2]+grid[1][1]+grid[2][0] != 15:
            return False
        return True
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        count = 0
        if len(grid) <3 or len(grid[0]) < 3:
            return 0
        # 用i代表行移动
        for i in range(0, len(grid)-2):
            # 用j代表列移动            
            for j in range(0, len(grid[0])-2):
                tmp = []
                for k in range(i, i+3):
                    tmp.append(grid[k][j:j+3])
                if self.check(tmp):
                    count += 1
        return count
        # for i in 
                
            
        
        

