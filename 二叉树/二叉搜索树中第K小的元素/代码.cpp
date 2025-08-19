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
    int kthSmallest(TreeNode *root, int k)
    {
        // //建大堆
        // //通过层序遍历将节点加入到堆中，利用k将堆中元素保持在k个
        // //时间复杂度O(n) 空间复杂度O(n)
        // priority_queue<int> pq;
        // queue<TreeNode*> q;
        // q.push(root);
        // while (!q.empty())
        // {
        //     int n = q.size();
        //     while (n--)
        //     {
        //         pq.push(q.front()->val);
        //         //堆中元素大于k个进行调整
        //         if (pq.size() > k) pq.pop();
        //         //节点为空就不进入队列
        //         if (q.front()->left) q.push(q.front()->left);
        //         if (q.front()->right) q.push(q.front()->right);
        //         q.pop();
        //     }
        // }
        // return pq.front();


        //二叉搜索树的中序遍历是递增的，所以
        //时间复杂度O(n) 空间复杂度O(n)
        stack<TreeNode*> st;
        int n = k - 1; //第1小的数就是栈顶元素，所以减一
        TreeNode* cur = root;
        while (!st.empty() || cur)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            if (n == 0) return st.top()->val;
            else 
            {
                TreeNode* node = st.top();
                st.pop();
                cur = node->right;
                --n;
            }
        }
        return -1;
    }
};