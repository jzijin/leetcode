class Solution(object):
    def getnum(self, point, grid):
        i = point[0]
        j = point[1]
        num = 0
        while i-1>=0:
            if grid[i-1][j] == '-1' or grid[i-1][j] == 'B':
                break
            if grid[i-1][j] == 'p':
                num += 1
                grid[i-1][j] = '-1'
                break
            i -= 1
        # print(num)
        i = point[0]
        j = point[1]
        while i+1<len(grid):
            if grid[i+1][j] == '-1' or grid[i+1][j] == 'B':
                break
            if grid[i+1][j] == 'p':
                num += 1
                grid[i+1][j] = '-1'
                break
            i += 1
        # print(num)
        i = point[0]
        j = point[1]
        # print("len", len(grid[0]))
        while j+1 <len(grid[0]):
            if grid[i][j+1] == '-1' or grid[i][j+1] == 'B':
                break
            if grid[i][j+1] == 'p':
                num += 1
                grid[i][j+1] = '-1'
                break
            j += 1
        # print(num)
        i = point[0]
        j = point[1]
        while j-1 >= 0:
            if grid[i][j-1] == '-1' or grid[i][j-1] == 'B':
                break
            if grid[i][j-1] == 'p':
                num += 1
                grid[i][j-1] = '-1'
                break
            j-= 1
        # print(num)
        return num
        
        
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        num = 0
        for i in range(0, len(board)):
            for j in range(0, len(board[0])):
                if board[i][j] == 'R':
                    num += self.getnum((i, j), board)
        return num
                    
        