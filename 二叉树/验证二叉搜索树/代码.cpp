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

    bool _isValidBST(TreeNode* root, long start, long end)
    {
        if (root == nullptr) return true;
        //左子树节点值大于等于右边界或者右子树节点值小于等于左边界返回false
        if (root->val <= start || root->val >= end) return false;
        bool ret1 = _isValidBST(root->left, start, root->val);
        bool ret2 = _isValidBST(root->right, root->val, end);
        return ret1 && ret2;
    }

    bool isValidBST(TreeNode *root)
    {
        // //递归
        // //时间复杂度O(n) 空间复杂度O(n);
        // return _isValidBST(root, LONG_MIN, LONG_MAX);
    
    
        //中序遍历
        //时间复杂度O(n) 空间复杂度O(n)
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur = root;
        long num = LONG_MIN;
        while (!st.empty())
        {
            while (cur->left)
            {
                cur = cur->left;
                st.push(cur);
            }
            TreeNode* node = st.top();
            st.pop();
            if (node->val <= num) return false;
            num = node->val;
            cur = node->right;
        }
        return true;
    }
};