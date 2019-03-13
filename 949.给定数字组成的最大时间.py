class Solution(object):
    # 当最高位取2的时候要判断是否可以
    def check(self, A, num):
        B = A[:]

        for i in range(0, len(B)):
            if B[i] == num:
                B.pop(i)
                break
        # 判断第二位
        for i in [0, 1, 2, 3]:
            a = 0
            for j in range(0, len(B)):
                if i == B[j]:
                    B.pop(j)
                    a = 1
                    break
            if a:
                break
        # print(B)
        # 判断第三位
        for i in [0, 1, 2, 3, 4, 5]:
            for j in range(0, len(B)):
                if i == B[j]:
                    return True
        # 第四位不需要判断

        return False

    def get_max_num(self, A, n, flag):
        while n >= 0:
            # print(n)
            for i in range(0, len(A)):
                if n == A[i]:
                    if flag == 1 and n == 2:
                        # 只有第一位才需要check
                        if self.check(A, n):
                            A.pop(i)
                            return n
                        # check 没过的话不需要处理
                    else:
                        A.pop(i)
                        return n

            n -= 1
        return -1

    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        if sum(A) == 0:
            return "00:00"
        max_time = ''

        # 第一位
        time = 2
        status = self.get_max_num(A, time, 1)
        # print(status)
        if status == -1:
            return ''
        max_time += str(status)
        # exit()

        # 第二位
        if status == 2:
            time = 3
        else:
            time = 9
        status = self.get_max_num(A, time, 0)
        print(status)
        if status == -1:
            return ''
        max_time += str(status)
        max_time += ':'

        # 第三位
        time = 5
        status = self.get_max_num(A, time, 0)
        if status == -1:
            return ''
        max_time += str(status)

        # 第四位
        time = 9
        status = self.get_max_num(A, time, 0)
        if status == -1:
            return ''
        max_time += str(status)

        return max_time
