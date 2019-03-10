
# 可以把 调用函数给去掉
class Solution(object):
    def count(self, grid, x, y):
        i = len(grid)
        j = len(grid[0])
        # print(i, j)
        sur = 0
        if x-1 >= 0:
            sur += min(grid[x][y], grid[x-1][y])
        if x+1 < i:
            sur += min(grid[x][y], grid[x+1][y])
        if y-1 >= 0:
            sur += min(grid[x][y], grid[x][y-1])
        if y+1 < j:
            sur += min(grid[x][y], grid[x][y+1])
        return sur
    
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # 算一下接触面有几个 算一下总的有几个正方形
        total = 0
        totalsur = 0
            
        
        for x in range(0, len(grid)):
            for y in range(0, len(grid[0])):                
                if grid[x][y] > 0:
                    total += grid[x][y]
                    totalsur += (grid[x][y] - 1)*2
                    # print(self.count(grid, x, y))
                    totalsur += self.count(grid, x, y)
        # print(totalsur, total)
        return 6*total - totalsur
        
        
        # for i in range(0, len(grid)):
        #     for j in range(0, len(grid[0])):



# 每一个坐标都可以提供 4*(个数) + 2 面积

# 但是由于临接正方形,会减少相邻最小值个数*2面积
class Solution:
    def surfaceArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        col = len(grid[0])
        res = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j]:
                    res += 4*grid[i][j] + 2
                if i :
                    res -= min(grid[i][j],grid[i-1][j]) * 2
                if j :
                    res -= min(grid[i][j],grid[i][j-1]) * 2
        return res
                