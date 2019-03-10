class RecentCounter(object):

    def __init__(self):
        self.mystack = []

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        self.mystack.append(t)
        count = 0
        length = len(self.mystack)
        i = 0
        while i < length:
            if self.mystack[i] >= t-3000:
                count += 1
            else:
                self.mystack.pop(i)
                length -= 1
                i -= 1
            i += 1
        return count
        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)