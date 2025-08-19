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

    void dfs(TreeNode* root, vector<int>& ret, int n)
    {
        if (root == nullptr) return ;
        if (n == ret.size()) ret.push_back(root->val);
        dfs(root->right, ret, n + 1);
        dfs(root->left, ret, n + 1);
        return ;
    }

    vector<int> rightSideView(TreeNode *root)
    {
        // //bfs
        // //层序遍历，从右往左遍历
        // //时间复杂度O(n) 空间复杂度O(n)
        // if (root == nullptr) return {};
        // queue<TreeNode*> q;
        // vector<int> ret;
        // q.push(root);
        // ret.push_back(root->val);
        // while (!q.empty())
        // {
        //     int n = q.size();
        //     while (n--)
        //     {
        //         //从右往左进行进入队列，先进入队列的元素就是所需要的
        //         if (q.front()->right) q.push(q.front()->right);
        //         if (q.front()->left) q.push(q.front()->left);
        //         q.pop();
        //     }
        //     //将队列首元素加入到数组中。注意：队列为空说明遍历节点完毕，不需要加入值到数组中
        //     if (!q.empty()) ret.push_back(q.front()->val);
        // }   
        // //队列为空，返回结果
        // return ret;


        //dfs（递归版本）
        //时间复杂度O(n) 空间复杂度O(n)
        vector<int> ret;
        dfs(root, ret, 0);
        return ret;


        //dfs（非递归版本）存储节点和深度的映射关系
        //时间复杂度O(n) 空间复杂度O(n)
        if (root == nullptr) return {};
        stack<pair<TreeNode*, int>> st;
        TreeNode* cur = root;
        vector<int> ret;
        st.push({root, 0});
        while (!st.empty())
        {
            auto [node, depth] = st.top();
            st.pop();
            if (depth == ret.size()) ret.push_back(node->val);
            //将左子树进行压栈，再压右子树，先进后出
            if (node->left) st.push({node->left, depth + 1});
            if (node->right) st.push({node->right, depth + 1});
        }
        return ret;
    }
};