#
# @lc app=leetcode.cn id=690 lang=python
#
# [690] 员工的重要性
#
# https://leetcode-cn.com/problems/employee-importance/description/
#
# algorithms
# Easy (47.54%)
# Total Accepted:    2.4K
# Total Submissions: 5K
# Testcase Example:  '[[1,2,[2]], [2,3,[]]]\n2'
#
# 给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。
# 
# 比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15,
# [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5,
# []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。
# 
# 现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。
# 
# 示例 1:
# 
# 
# 输入: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
# 输出: 11
# 解释:
# 员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。
# 
# 
# 注意:
# 
# 
# 一个员工最多有一个直系领导，但是可以有多个直系下属
# 员工数量不超过2000。
# 
# 
#
"""
# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
# TODO:如何用 哈希表和广度优先搜索简化呢？？？ 递归 非递归的 转化？？？
# BFS 法:
# from collections import deque
# class Solution:
#     def getImportance(self, employees, i):
#         """
#         :type employees: Employee
#         :type id: int
#         :rtype: int
#         """
#         dic = {i.id:i for i in employees}
#         visited = set()
#         ret = 0
#         q = deque()
#         q.append(dic[i])
#         while q:
#             cur = q.popleft()
#             ret+=cur.importance
#             visited.add(cur.id)
#             for i in cur.subordinates:
#                 if i not in visited:
#                     q.append(dic[i])
#         return ret
class Solution(object):
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        # print(employees)
        importtance = 0
        # flag = {}
                
        for employee in employees:
            if employee.id == id:
                # flag[id] = 1
                importtance += employee.importance
                for i in employee.subordinates:
                    importtance += self.getImportance(employees, i)
        return importtance
        
        

