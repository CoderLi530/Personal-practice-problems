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
    //递归
    //时间复杂度O(n) 空间复杂度O(logn)
    TreeNode* _sortedArrayToBST(vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;
        int mid = (left + right + 1) / 2;
        TreeNode* left_node = _sortedArrayToBST(nums, left, mid - 1);
        TreeNode* right_node = _sortedArrayToBST(nums, mid + 1, right);
        TreeNode* root = new TreeNode(nums[mid], left_node, right_node);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return _sortedArrayToBST(nums, 0, nums.size() - 1);         
    }
};