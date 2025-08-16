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
    //递归版本的中序遍历
    void recurinorderTraversal(TreeNode* root, vector<int>& ret)
    {
        if (root == nullptr) return;
        recurinorderTraversal(root->left, ret);
        ret.push_back(root->val);
        recurinorderTraversal(root->right, ret);
    }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        // //使用递归
        // //时间复杂度O(n) 空间复杂度O(n)
        // if (root == nullptr) return {};
        // vector<int> ret;
        // recurinorderTraversal(root, ret);
        // return ret;


        // //使用非递归 -- 利用栈实现中序遍历的逻辑
        // //时间复杂度O(n) 空间复杂度O(n)
        // if (root == nullptr) return {};
        // stack<TreeNode*> st;
        // vector<int> ret;
        // TreeNode* cur = root;
        // st.push(cur);
        // cur = cur->left;
        // while (!st.empty())
        // {
        //     //先将左节点全部入栈
        //     while (cur)
        //     {
        //         st.push(cur);
        //         cur = cur->left;    
        //     }
        //     //左节点全部入栈之后，将栈顶元素保存在ret中，将右节点入栈
        //     TreeNode* tmp = st.top();
        //     st.pop();
        //     ret.push_back(tmp->val);
        //     if (tmp->right) 
        //     {   
        //         st.push(tmp->right);
        //         cur = tmp->right;
        //     }
        // }
        // return ret;
    
    
        //使用morris算法优化空间复杂度
        //时间复杂度O(n) 空间复杂度O(1)
        //将左子树的最右节点指向根节点
        TreeNode* cur1 = root;
        TreeNode* cur2 = nullptr;
        vector<int> ret;
        while (cur1)
        {
            cur2 = cur1->left;
            //找到左子树的最右节点
            if (cur2)
            {
                //cur2不断往右子树走
                while (cur2->right && cur2->right != cur1)
                {
                    cur2 = cur2->right;
                }
                //当右节点的right为空，说明走到叶节点了，进行连接
                if (cur2->right == nullptr)
                {
                    cur2->right = cur1;
                    cur1 = cur1->left;
                    continue; //往左子树往下走
                }
                else //斩断连接
                {   
                    cur2->right = nullptr;
                }
            }
            //走到这里说明cu1已经到了最左子树
            ret.push_back(cur1->val);
            //左子树走完走右子树
            cur1 = cur1->right;
        }
    }   
};