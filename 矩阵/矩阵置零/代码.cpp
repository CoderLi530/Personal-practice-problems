class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        // //1. 使用队列保存元素为0的位置，然后遍历数组修改对应列行的值
        // //时间复杂度O(nm) 空间复杂度O(k) 最坏情况O(mn)
        // queue<pair<int, int>> q;
        // int m = matrix.size();
        // int n = matrix[0].size();
        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j) if (matrix[i][j] == 0) q.push({i, j});
        // }
        // while (!q.empty())
        // {
        //     auto [x, y] = q.front();
        //     q.pop();
        //     //修改行
        //     for (int j = 0; j < n; ++j)
        //     {
        //         matrix[x][j] = 0;
        //     }
        //     //修改列
        //     for (int i = 0; i < m; ++i)
        //     {
        //         matrix[i][y] = 0;
        //     }
        // }


        // //2. 使用标记数组，将空间复杂度降到O(m+n)
        // //时间复杂度O(mn) 空间复杂度O(m + n)
        // int m = matrix.size();
        // int n = matrix[0].size();
        // vector<bool> row(m), col(n); //使用两个数组存储
        // //遍历数组，遇到0修改row和col对应位置为true
        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j) 
        //     {
        //         if (matrix[i][j] == 0) row[i] = col[j] = true;
        //     }
        // }
        // //遍历数组，遇到true改成0
        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j) 
        //     {
        //         //对对应位置的行列修改成0，所以判断条件有一个符合就进行修改
        //         if (row[i] || col[j]) matrix[i][j] = 0;
        //     }
        // }


        //3. 使用标记变量，将空间复杂度降到O(1)
        //时间复杂度O(mn) 空间复杂度O(1)
        //先标记第一行和第一列是否出现0
        //然后从第二行和第二列开始遍历，出现0把对应第一行和第一列位置置0
        //然后遍历第二行和第二列，将行列的值修改成0
        //最后判断第一行和第一列是否需要修改为0
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag_row = false, flag_col = false;
        //第一行
        for (int j = 0; j < n; ++j) if (matrix[0][j] == 0) flag_row = true;
        //第一列
        for (int i = 0; i < m; ++i) if (matrix[i][0] == 0) flag_col = true;
        //遍历剩余的位置进行置0
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j) if (matrix[i][j] == 0) matrix[0][j] = matrix[i][0] = 0;
        }
        //遍历剩余的位置，将行列的值进行修改
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j) if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        }
        //对第一行和第一列进行修改
        if (flag_row)
        {
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        if (flag_col)
        {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};