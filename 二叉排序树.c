//https://www.cnblogs.com/Camilo/p/3912111.html
// binary serch Tree 二叉搜索树
//一棵结点中存储着关键码（数据）的二叉树是二叉搜索（排序）树，当且仅当通过中序遍历这棵二叉排序树得到的关键码序列是一个递增序列

/*
1.      二叉排序树

二叉排序树(Binary Sort Tree)或者是一棵空树，或者是具有下列性质的二叉树：

(1)若左子树不空，则左子树上所有结点的值均小于它的根结点的值；

(2)若右子树不空，则右子树上所有结点的值均大于它的根结点的值；

(3)左、右子树也分别为二叉排序树；

(4)没有结点值相同的结点。

二叉排序树又称二叉查找树(Binary Search Tree)，亦称二叉搜索树。通常采用二叉链表作为二叉排序树的存储结构。中序遍历二叉排序树可以得到关键字有序的序列，即一个无序序列可以通过构造二叉排序树成为有序序列，构造树的过程即为对无序序列排序的过程。
*/
// 查找
/*
 * 在以T为根结点的树中，查找与给定值key相同的结点。
 * 如果存在返回指向该结点的指针，否则返回空指针。
 */
BiTree SearchBST1(BiTree T, TElemType key)
{
    if (!T) //空树，查找失败
        return NULL;
    else if (key == T->data) //查找成功
        return T;
    else if (key < T->data) //在左子树中继续查找
        return SearchBST1(T->lchild, key);
    else //在右子树中继续查找
        return SearchBST1(T->rchild, key);
}