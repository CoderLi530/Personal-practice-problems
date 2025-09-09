class Solution
{
public:

    void backtrack(vector<string>& ret, string& tmp, int n, int left_count, int right_count)
    {
        //tmp中的括号数量正确加入到ret中
        if (tmp.size() == 2 * n)
        {
            ret.push_back(tmp);
            return ;
        }
        //加入左括号
        if (left_count < n)
        {
            tmp += '(';
            backtrack(ret, tmp, n, left_count + 1, right_count);
            tmp.pop_back(); //回溯
        }
        //加入右括号
        //只有有了左括号才可以加右括号
        if (right_count < left_count)
        {
            tmp += ')';
            backtrack(ret, tmp, n, left_count, right_count + 1);
            tmp.pop_back(); //回溯
        }
    }

    vector<string> generateParenthesis(int n)
    {
        //回溯
        //时间复杂度O(4^n / √n) 空间复杂度O(n)
        vector<string> ret; //返回数组
        string tmp; //临时
        backtrack(ret, tmp, n, 0, 0);
        return ret;
    }
};