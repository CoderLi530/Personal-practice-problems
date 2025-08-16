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
    int maxDepth(TreeNode *root)
    {
        // //递归
        // //时间复杂度O(n) 空间复杂度O(n)
        // if (root == nullptr) return 0;
        // return max(maxDepth(root->left), maxDepth(root->right)) + 1;


        //队列 + 层序遍历
        //时间复杂度O(n) 空间复杂度O(n)
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        int ret = 0;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            ++ret;
        }
        return ret;
    }
};