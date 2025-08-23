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

    TreeNode* _buildTree(vector<int>& preorder, unordered_map<int, int>& hash, int pre_left, int pre_right, int in_left, int in_right)
    {
        if (pre_left > pre_right) return nullptr;
        int pre_root = pre_left; //前序遍历序列根节点的位置
        int in_root = hash[preorder[pre_root]]; //中序遍历序列根节点的位置
        TreeNode* node = new TreeNode(preorder[pre_root]); //创建节点
        int count = in_root - in_left; //子树的数量
        node->left = _buildTree(preorder, hash, pre_left + 1, pre_left + count, in_left, in_root - 1);
        node->right = _buildTree(preorder, hash, pre_left + count + 1, pre_right, in_root + 1, in_right);
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // //前序遍历序列找根节点，中序遍历找左右子树
        // //使用哈希表存储中序遍历序列，方便查找
        // //时间复杂度O(n) 时间复杂度O(n)
        // unordered_map<int, int> hash;
        // for (int i = 0; i < inorder.size(); ++i)
        // {
        //     hash[inorder[i]] = i;
        // }
        // return _buildTree(preorder, hash, 0, preorder.size() - 1, 0, inorder.size() - 1);


        //迭代
        stack<TreeNode*> st;
    }
};