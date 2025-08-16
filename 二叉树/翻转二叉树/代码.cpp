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
    TreeNode *invertTree(TreeNode *root)
    {
        // //递归
        // //时间复杂度O(n) 空间复杂度O(n)
        // if (root == nullptr) return nullptr;
        // TreeNode* left_node = invertTree(root->left);
        // TreeNode* right_node= invertTree(root->right);
        // TreeNode* tmp = left_node;
        // root->left = right_node;
        // root->right = tmp;
        // return root;

        // 使用队列
        //时间复杂度O(n) 空间复杂度O(n)
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            // 出队列
            int n = q.size();
            TreeNode* cur = q.front();
            while (n--)
            {
                TreeNode* cur = q.front();
                // 至少有一个子节点才会进行交换，没有子节点不交换
                if (cur->left || cur->right)
                {
                    if (cur->left) q.push(cur->left);
                    if (cur->right) q.push(cur->right);
                    // 进行交换两个节点
                    TreeNode *tmp = cur->left;
                    cur->left = cur->right;
                    cur->right = tmp;
                }
                q.pop();    
            }
        }
        return root;
    }
};