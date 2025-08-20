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

    void dfs(TreeNode* root, vector<int>& nums)
    {
        if (root == nullptr) return ;
        nums.push_back(root);
        dfs(root->left, nums);
        dfs(root->right, nums);
    }

    void flatten(TreeNode *root)
    {
        // //前序遍历（递归），将前序遍历的结果存储在数组中
        // //时间复杂度O(n) 空间复杂度O(n)
        // vector<TreeNode*> nums;
        // dfs(root, nums);
        // //将数组中的节点重新连接
        // for (int i = 1; i < nums.size(); ++i)
        // {
        //     nums[i - 1]->right = nums[i];
        //     nums[i - 1]->left = nullptr;
        // }


        // //前序遍历（非递归），将前序遍历的结果存储在数组中
        // //时间复杂度O(n) 空间复杂度O(n)
        // stack<TreeNode*> st;
        // vector<TreeNode*> nums;
        // TreeNode* cur = root;
        // while (!st.empty() || cur)
        // {
        //     //将根节点、左子树进栈
        //     while (cur)
        //     {
        //         st.push(cur);
        //         nums.push_back(cur);
        //         cur = cur->left;
        //     }
        //     //将右子树进栈
        //     TreeNode* node = st.top();
        //     st.pop();
        //     cur = node->right;
        // }
        // for (int i = 1; i < nums.size(); ++i)
        // {
        //     nums[i - 1]->right = nums[i];
        //     nums[i - 1]->left = nullptr;
        // }


        //原地修改
        //时间复杂度O(n) 空间复杂度O(1)
        TreeNode* cur = root;
        while (cur)
        {
            //判断是否有左子树
            if (cur->left)
            {
                TreeNode* prev = nullptr;
                TreeNode* node = cur->left;
                while (node)
                {
                    prev = node;
                    node = node->right;
                }
                //将当前节点的右子树连接到左子树的最右节点
                prev->right = cur->right;
                //修改节点的左子树位置
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};