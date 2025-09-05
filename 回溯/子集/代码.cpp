class Solution
{
public:

    void backtrack(vector<vector<int>>& ret, vector<int>& nums, int start, vector<int> tmp)
    {
        //将当前子集加入到结果集
        ret.push_back(tmp);
        //避免重复
        for (int i = start; i < nums.size(); ++i)
        {
            //选择当前元素
            tmp.push_back(nums[i]);
            //递归选择当前元素的下一个元素
            backtrack(ret, nums,  i + 1, tmp);
            //进行回溯
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        // //回溯
        // //时间复杂度O(n*2^n) 空间复杂度O(2^n)
        // vector<vector<int>> ret;
        // vector<int> tmp;
        // backtrack(ret, nums, 0, tmp);
        // return ret;


        //迭代
        //时间复杂度O(n*2^n) 空间复杂度O(2^n)
        vector<vector<int>> ret;
        vector<int> tmp;
        int n = nums.size();
        for (int i = 0; i < (1 << n); ++i)
        {
            //清空原子集，创建新子集
            tmp.clear();
            for (int j = 0; j < n; ++j)
            {
                //哪个元素存在，选中那个元素
                if (i & (1 << j)) tmp.push_back(nums[j]);
            }
            //更新子集
            ret.push_back(tmp);
        }
        return ret;
    }
};

