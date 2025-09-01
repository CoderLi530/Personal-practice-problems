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

    //将节点的父节点存储在哈希表中
    void dfs(TreeNode* root, unordered_map<int, TreeNode*>& hash)
    {
        if (root == nullptr) return ; 
        if (root->left)
        {
            hash[root->left->val] = root;
            dfs(root->left, hash);
        }
        if (root->right)
        {
            hash[root->right->val] = root;
            dfs(root->right, hash);
        }
    }

    //递归
    TreeNode* _lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr) return  nullptr;
        if (root == p || root == q) return root;
        TreeNode* node1 = _lowestCommonAncestor(root->left, p, q);
        TreeNode* node2 = _lowestCommonAncestor(root->right, p, q);  
        //p和q找到了，当前root就是最近公共祖先
        if (node1 && node2) return root;
        //p，q没找到，返回另一个
        return node1 ? node1 : node2;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // //存储父节点
        // //时间复杂度O(N) 空间复杂度O(N)
        // unordered_map<int, TreeNode*> hash; //存储每个节点的父节点
        // unordered_map<int, bool> vis; //记录已访问过的父节点
        // //1. 使用哈希表存储每个节点的父节点
        // hash[root->val] = nullptr; //根节点的父节点为空
        // dfs(root, hash);
        // //2. 从p节点开始访问其父节点，使用哈希表存储已经访问过的父节点
        // while (p)
        // {
        //     vis[p->val] = true;
        //     p = hash[p->val];
        // }
        // //3. 从q节点开始访问其父节点，在哈希表中查找，如果存在，说明该节点就是最近公共祖先
        // while (q)
        // {
        //     if (vis[q->val]) return q;
        //     q = hash[q->val];
        // }
        // return nullptr;


        //dfs
        //时间复杂度O(N) 空间复杂度O(N)
        return _lowestCommonAncestor(root, p, q);
    }
};