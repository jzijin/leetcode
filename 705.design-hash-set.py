#
# @lc app=leetcode.cn id=705 lang=python
#
# [705] Design HashSet
#
# https://leetcode-cn.com/problems/design-hashset/description/
#
# algorithms
# Easy (52.80%)
# Total Accepted:    2.7K
# Total Submissions: 5.1K
# Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
#
# 不使用任何内建的哈希表库设计一个哈希集合
# 
# 具体地说，你的设计应该包含以下的功能
# 
# 
# add(value)：向哈希集合中插入一个值。
# contains(value) ：返回哈希集合中是否存在这个值。
# remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
# 
# 
# 
# 示例:
# 
# MyHashSet hashSet = new MyHashSet();
# hashSet.add(1);         
# hashSet.add(2);         
# hashSet.contains(1);    // 返回 true
# hashSet.contains(3);    // 返回 false (未找到)
# hashSet.add(2);          
# hashSet.contains(2);    // 返回 true
# hashSet.remove(2);          
# hashSet.contains(2);    // 返回  false (已经被删除)
# 
# 
# 
# 注意：
# 
# 
# 所有的值都在 [1, 1000000]的范围内。
# 操作的总数目在[1, 10000]范围内。
# 不要使用内建的哈希集合库。
# 
# 
#


class MyHashSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = {}

    def add(self, key):
        """
        :type key: int
        :rtype: None
        """
        if key in self.dic:
            self.dic[key] += 1
        else:
            self.dic[key] = 1

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        if key in self.dic:
            self.dic.pop(key)

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        if key in self.dic:
            return True
        return False


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)

