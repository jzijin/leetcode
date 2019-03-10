class Solution(object):
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        myqueue = []
        myqueue.append((sr, sc)) 
        flag = image[sr][sc]
        image[sr][sc] = 65536
        target = []
        target += myqueue
        while True:
            count = 0
            tmp = []
            for (i, j) in myqueue:
                if i+1 < len(image) and image[i+1][j] == flag:
                    count += 1
                    tmp.append((i+1, j))
                    image[i+1][j] = 65536
                if i-1 >= 0 and image[i-1][j] == flag:
                    count += 1
                    tmp.append((i-1, j))
                    image[i-1][j] = 65536
                if j+1 <len(image[0]) and  image[i][j+1] == flag:
                    count += 1
                    tmp.append((i, j+1))
                    image[i][j+1] = 65536
                if j-1 >= 0 and image[i][j-1] == flag:
                    count += 1
                    tmp.append((i, j-1))
                    image[i][j-1] = 65536
            # print(tmp)
            myqueue = tmp
            target += myqueue
            if not count:
                break
        print(target)





class Solution(object):
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        # 按照长度排序
        words = sorted(words,key = lambda i:len(i),reverse=True) 
        # print("sdlfjlskdf")
        # print(words)
        # 把拍照转化成小写
        license = []
        licensePlate = licensePlate.lower()
        for i in licensePlate:
            if i>='a' and i<='z':
                license.append(i)
        # license = list(set(license))
        # tmp = []
        length = len(license)-1
        i = 0
        while i < length:
            # tmp.append(license[i])
            if license[i+1] in license[i]:
                # print(license)
                license[i] += license[i+1]
                license.remove(license[i+1])
                length -= 1
                i -= 1
            i += 1
            
        print(license)
        
        target = []
        for word in words :
            flag = 1;
            for j in license:
                if j not in word:
                    flag=0
                    break
            if flag:
                target.append(word)
        print(target)
# class Solution(object):
#     def floodFill(self, image, sr, sc, newColor):
#         """
#         :type image: List[List[int]]
#         :type sr: int
#         :type sc: int
#         :type newColor: int
#         :rtype: List[List[int]]
#         """        
#         m=len(image)
#         n=len(image[0])
#         oldColor=image[sr][sc]
#         if oldColor==newColor:
#             return image
#         image[sr][sc]=newColor
#         if sr-1>=0  and image[sr-1][sc]==oldColor :
#             self.floodFill(image, sr-1, sc, newColor)
#         if sr+1<m and image[sr+1][sc]==oldColor :
#             self.floodFill(image, sr+1, sc, newColor)
#         if sc-1>=0 and image[sr][sc-1]==oldColor :
#             self.floodFill(image, sr, sc-1, newColor)
#         if sc+1<n and image[sr][sc+1]==oldColor :
#             self.floodFill(image, sr, sc+1, newColor)
#         return image