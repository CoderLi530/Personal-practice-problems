/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        //使用栈存储节点，然后遍历栈，找到最近公共祖先
        //如果两个目标节点同时进栈，说明公共祖先不是目标节点，否则先进栈的目标节点就是最近公共祖先
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            while (n--)
            {
                TreeNode* node = que.front();
                if (node == p || node == q) return node;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (node->left || node->right)
                {
                    if (node->left && (node->left == p || node->left == q))
                    {
                        if (node->right && (node->right == p || node->right == q))
                        {
                           return node; 
                        }
                        else return node->left;
                    }
                    if (node->right == p || node->right == q) return node->right;
                }
                que.pop();
            }
        }
        return nullptr;
    }
};