class Solution(object):
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """ 
        # TODO: 尝试用矩阵的方法解这道题
        surf = 0
        for i in range(0, len(points)):
            for j in range(i+1, len(points)):
                for k in range(j+1, len(points)):
                    points1 = points[i]
                    points2 = points[j]
                    points3 = points[k]
                    
                    # 计算出三条边
                    length1 =((points2[1]-points1[1])**2 + (points2[0]-points1[0])**2)**0.5
                    length2 = ((points3[1]-points1[1])**2 + (points3[0]-points1[0])**2)**0.5
                    length3 = ((points2[1]-points3[1])**2 + (points2[0]-points3[0])**2)**0.5
                    
                    # 计算cos的值
                    cosval = (length1**2 + length2**2 - length3**2)/(2*length1*length2)
                    # 计算面积大小
                    surval = 0.5*length1*length2*abs((1-cosval**2))**0.5
                    if surval > surf:
                        surf = surval
        return surf
                    
        