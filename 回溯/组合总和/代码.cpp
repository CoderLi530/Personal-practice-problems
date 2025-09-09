class Solution
{
public:

    void backtrack(vector<vector<int>>& ret, vector<int>& candidates, vector<int>& tmp, int target, int& sum, int start)
    {
        //符合条件加入到ret中
        if (sum == target) ret.push_back(tmp);
        //大于目标值返回
        if (sum > target) return ;
        for (int i = start; i < candidates.size(); ++i)
        {
            //更新tmp和sum
            tmp.push_back(candidates[i]);
            sum += candidates[i];
            //传入当前位置，去掉重复元素
            backtrack(ret, candidates, tmp, target, sum, i);
            //撤销上一次操作
            sum -= tmp.back();
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        //回溯
        //时间复杂度O(n^k) 空间复杂度O(k) n为candidates的长度，k为组合元素的最大可能数量
        vector<vector<int>> ret; //返回数组
        vector<int> tmp; //临时数组
        int sum = 0; //总和
        backtrack(ret, candidates, tmp, target, sum, 0);        
        return ret;
    }
};