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
    bool check(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr) return true;
        if ((root1 == nullptr && root2) || (root1 && root2 == nullptr)) return false;
        if (root1->val != root2->val) return false;
        if (!check(root1->left, root2->right) || !check(root1->right, root2->left)) return false;
        return true;
    }

    bool isSymmetric(TreeNode *root)
    {
        // // 使用递归
        // //时间复杂度O(n) 空间复杂度O(n)
        // return check(root, root);

        //使用队列 + 层序遍历
        //时间复杂度O(n) 空间复杂度O(n)
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty())
        {
            //取两个节点进行比较
            TreeNode* node1 = q.front(); q.pop();
            TreeNode* node2 = q.front(); q.pop();
            //两个相同空节点就继续弹出队列
            if (node1 == nullptr && node2 == nullptr) continue;
            //值不相等或者有一方为空就返回false，注意：先判断节点是否为空，再判断节点的值
            if ((!node1 || !node2) || node1->val != node2->val) return false;
            //交叉进入队列
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }   
        //走到这里说明二叉树是对称的
        return true;
    }
};