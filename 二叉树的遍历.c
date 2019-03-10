// 总结二叉树中序 前序 后序 层序遍历的 递归 非递归写法
//https://leetcode-cn.com/problems/construct-string-from-binary-tree/
//https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/
//https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
//https://leetcode-cn.com/problems/diameter-of-binary-tree/
//https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
//https://leetcode-cn.com/problems/binary-tree-paths/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 递归写法
//1、前序
void PreOrder(struct TreeNode *root)
{
    if (root == NULL)                 //若结点为空
    {
        printf("# ");
        return;
    }
    printf("%c", root->data);        // 处理根节点的数据
    PreOrder(root->left);             //前序访问左子树
    PreOrder(root->right);            //前序访问右子树
}
// 2、 中序
void InOrder(struct TreeNode *root)
{
    if (root == NULL)                 //若结点为空
    {
        printf("# ");
        return;
    }
    InOrder(root->left);             //前序访问左子树
    printf("%c", root->data);        // 处理根节点的数据
    InOrder(root->right);            //前序访问右子树
}
// 3、后序
void PostOrder(struct TreeNode *root)
{
    if (root == NULL)                 //若结点为空
    {
        printf("# ");
        return;
    }
    PostOrder(root->left);             //前序访问左子树
    PostOrder(root->right);            //前序访问右子树
    printf("%c", root->data);        // 处理根节点的数据
}

// 层序遍历不能用递归来实现

// 非递归实现
// 1、前序
void PreOrder(struct TreeNode *root)
{
    if (root == NULL)                 //若结点为空
    {
        printf("# ");
        return;
    }
    s = STACK()
    while(root != NULL || ! s.is_empty())
    {
        while(root != NULL)
        {
            proc(root->val) // 处理节点数据
            s.push(root->right); // 把右子树入栈
            root = root->left;// 沿着左分支继续
        }
        root = s.pop();// 遇到空树回溯
        
    }

}

//2、中序
void InOrder(struct TreeNode *root)
{
    if(root == NULL)
    {
        return；
    }
    TreeNode *cur, *top, *last = NULL;
    cur = root;
    s = STACK()
    while (cur != NULL || !s.empty())
    {
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }

        top = s.top();

        if (top->right == NULL || top->right == last){
            s.pop();
            printf("%c ", top->data);
            last = top;
        }
        else {
            cur = top->right;
        }
    }
}

//3、 后序
void PostOrder(struct TreeNode *root)
{
    s = STACK()
    while(root != NULL || ！s.is_empty())
    {
        while(root != NULL) // 直到栈顶的两子树为空
        {
            s.push(root)
            root = root->left if root->left != NULL else root->right // 能左则左 否则向右
        }
        root = s.pop()// 弹出栈顶数据
        proc(root->val);// 处理数据
        if(!s.is_empty() && s.top()->left = root)
        {
            root = s.top()->right; // 栈不空且当前节点是栈顶的左子节点
        }
        else
        {
            root = NULL;// 没有右子树或右子树遍历完毕，强迫退栈
        }
        
    }
}
// 4、 层序 遍历 需要用到队列 https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
// https://leetcode-cn.com/problems/find-bottom-left-tree-value/
void LevelOrder(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    s = queue();
    queue.push(root)
    while(! queue.is_empty())
    {
        proc(queue.pop());
        next_node = queue.pop(0)
        if next_node.left is not None:
            queue.push(next_node.left)
        if next_node.right is not None:
            queue.push(next_node.right)
    }
}
