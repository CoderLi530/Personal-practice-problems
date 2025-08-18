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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        //使用队列
        //时间复杂度O(n) 空间复杂度O(n)
        if (root == nullptr) return {};
        vector<vector<int>> ret; //返回的数组
        queue<TreeNode*> q; //队列，存储节点
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            //将每层的节点对应的值加入到一个数组中
            vector<int> tmp;
            while (n--)
            {
                tmp.push_back(q.front()->val);
                //加入下一层节点，为空就不用添加了
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            ret.push_back(tmp);
        }
        //队列为空，完成了层序遍历
        return ret;
    }
};