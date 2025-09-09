class Solution
{
public:

    void backtrack(vector<string>& arr, vector<string>& ret, const char* str, int start, string& tmp)
    {
        //对于数字字符串的遍历判断
        if (start == strlen(str)) return ;
        //数字对应字符串的下标
        int index = str[start] - '0';
        //对字符串进行遍历
        for (int i = 0; i < arr[index].size(); ++i)
        {
            //保存字符
            tmp += arr[index][i];
            //进行回溯
            backtrack(arr, ret, str, start + 1, tmp);
            //进行筛选，符合数量条件的字符串进入ret
            if (tmp.size() == strlen(str)) ret.push_back(tmp);
            //撤销上一次修改
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        //回溯
        //时间复杂度O(3^m + 4^n) 空间复杂度O(m + n) m为三个字母对应的数字，n为4个字母对应的数字
        //字符数组
        vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret; //返回的数组
        string tmp; //临时数组
        backtrack(arr, ret, digits.c_str(), 0, tmp);
        return ret;
    }  
};