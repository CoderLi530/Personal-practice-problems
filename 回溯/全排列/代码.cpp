class Solution
{
public:

    void backtrack(vector<vector<int>>& ret, vector<int>& nums, int start, int end)
    {
        if (start == end)
        {
            ret.push_back(nums);
            return;
        }
        for (int i = start; i < end; ++i)
        {
            //进行交换，分出情况
            swap(nums[i], nums[start]);
            //往一条路径走
            backtrack(ret, nums, start + 1, end);
            //进行回溯
            swap(nums[i], nums[start]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        //回溯
        //时间复杂度O(N*N!) 空间复杂度O(N*N)
        //[1, 2, 3]
        vector<vector<int>> ret;
        backtrack(ret, nums, 0, nums.size());   
        return ret;   
    }
};