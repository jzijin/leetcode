class Solution(object):
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        target = {}
        for i in points:
            tmp = i[0]**2+i[1]**2
            target[(i[0],i[1])] = tmp
        target = sorted(target.items(),key = lambda x:x[1])
        return_target = []
        for i in range(K):
            return_target.append([target[i][0][0], target[i][0][1]])
        return return_target