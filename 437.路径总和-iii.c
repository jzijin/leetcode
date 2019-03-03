/*
 * @lc app=leetcode.cn id=437 lang=c
 *
 * [437] 路径总和 III
 *
 * https://leetcode-cn.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (46.94%)
 * Total Accepted:    3.3K
 * Total Submissions: 7K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树，它的每个结点都存放着一个整数值。
 * 
 * 找出路径和等于给定数值的路径总数。
 * 
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
 * 
 * 示例：
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * 返回 3。和等于 8 的路径有:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3.  -3 -> 11
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
int get_sum(int val, struct TreeNode* root, int target)
{
    int count = 0;
    if(root == NULL)
    {
        return 0;
    }
    val += root->val;
    if(val == target)
    {
        count += 1;
    }
    // printf("%d\n", val);
    count += get_sum(val, root->left, target);
    // printf("%d\n", val);
    count += get_sum(val, root->right, target);
    // printf("%d\n", count);
    return count;
}
int pathSum(struct TreeNode* root, int sum) {
    if(root == NULL)
    {
        return 0;
    }
    // static int count = 0;
    int target;
    target = get_sum(0, root, sum); 
    // printf("%d\n", target);
    target += pathSum(root->left, sum);
    target += pathSum(root->right, sum);   
    return target;

}

*/
int root_pathSum(struct TreeNode* root, int sum) 
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->val == sum)
	{
		return 1 + root_pathSum(root->left, 0) + root_pathSum(root->right, 0);
	}
	else
	{
        // 换一个角度思考问题 为什么一定要传 sum 呢 也可以用sum-当前节点的值啊 达到更好的效果
		return root_pathSum(root->left, sum-root->val) + root_pathSum(root->right, sum-root->val) ;
	}
}
int pathSum(struct TreeNode* root, int sum)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return root_pathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
}

