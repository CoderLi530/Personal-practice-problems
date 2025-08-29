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
    // void dfs(TreeNode* root, int target, int& count, long num)
    // {
    //     if (root == nullptr) return ;
    //     if (root->val + num== target) ++count;
    //     dfs(root->left, target, count, num + root->val);
    //     dfs(root->right, target, count, num + root->val);
    // }

    // void _pathSum(TreeNode* root, int target, int& count)
    // {
    //     if (root == nullptr) return ;
    //     dfs(root, target, count, 0);
    //     _pathSum(root->left, target, count);
    //     _pathSum(root->right, target, count);
    // }

    // 前缀和
    int dfs(TreeNode *root, int target, unordered_map<long, int> &hash, long num)
    {
        if (root == nullptr)
            return 0;
        int ret = 0;
        if (hash.count(num + root->val - target))
            ret = hash[num + root->val - target];
        hash[num + root->val]++;
        ret += dfs(root->left, target, hash, num + root->val);
        ret += dfs(root->right, target, hash, num + root->val);
        // 准备遍历右子树，移除左子树的前缀和
        hash[num + root->val]--;
        return ret;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        //     //dfs
        //     //从每个根节点作为起点进行前序遍历 -- 进行前序遍历的前序遍历
        //     //时间复杂度O(N^2) 空间复杂度O(N)
        //     int count = 0;
        //     _pathSum(root, targetSum, count);
        //     return count;

        // 前缀和
        // 时间复杂度O(N) 空间复杂度O(N)
        unordered_map<long, int> hash;
        hash[0] = 1; // 遇到等于targetSum时需要计算路径
        return dfs(root, targetSum, hash, 0);
    }
};