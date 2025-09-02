/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:

    int dfs(TreeNode* root, int& ret)
    {
        if (root == nullptr) return 0;
        //对于路径和小于0的值不予取值
        int num1 = max(dfs(root->left, ret), 0);
        int num2 = max(dfs(root->right, ret), 0);
        ret = max(root->val + num1 + num2, ret); //保存当前树的最大路径和
        return root->val + max(num1, num2); //返回有效最大路径和
    }

    int maxPathSum(TreeNode *root)
    {
        //dfs
        //时间复杂度O(N) 空间复杂度O(N)
        //对于叶子节点保存本身的值，对于根节点保存本身的值和子树最大值之和
        //对于返回路径和小于0不予取值
        int ret = INT_MIN;
        dfs(root, ret);
        return ret;
    }
};