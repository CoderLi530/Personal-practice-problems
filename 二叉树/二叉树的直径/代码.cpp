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
    int ret = 0;

    int _diameterOfBinaryTree(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int num1 = _diameterOfBinaryTree(root->left);
        int num2 = _diameterOfBinaryTree(root->right);
        ret = max(ret, num1 + num2);
        return max(num1, num2) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        //递归，左子树和右子树的最大深度之和
        _diameterOfBinaryTree(root);   
        return ret;
    }
};