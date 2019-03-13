/*
AVL树的动态操作（插入/删除）将采用如下的方式实现：首先根据关键码确定位置，实际插入或删除的结点
。如果这时出现树失衡的情况，就设法进行局部调整，回复树的平衡。下面可以看到，插入和删除操作后的
调整都可以在树中的一条路径上一遍完成，因此插入和删除操作的时间代价都是 lognc
B树是一种动态的多分支树。通过维护结点分支数保证树具有良好的结构。B树常用于大型数据库的索引。
很适合外存（外存字典0）的存储。外存设备的特点是查找一个存储块的速度较慢，而连续读取一块的速度较快
*/
def LL(self, a, b):# 详情参考图
    a.left = b.right
    b.right = a
    a.bf = b.bf = 0
    return a

def RR(self, a, b):
    a.right = b.left
    b.left = a
    a.bf = b.bf = 0
    return b

def LR(self, a, b):  # 详情参考图
    c = b.right
    a.left, b.right = c.right, c.left
    c.left, c.right = b, a
    if c.bf == 0: # c本身就是插入结点
        a.bf = b.bf = 0
    elif c.bf == 1: # 新结点在c的左子树
        a.bf = -1
        b.bf = 0
    else:           # 新结点在c的右子树
        a.bf = 0
        b.bf = 1
    return c

def RL(self, a,b ):
    c = a.left
    a.right, b.left = c.left, c.right
    c.left, c.right = a, b
    if c.bf == 0:
        a.bf=0
        b.bf = 0
    elif c.bf == 1
        a.bf = 0
        b.bf = -1
    else:
        a.bf = 1
        b.bf = 0
    c.bf = 0
    return c