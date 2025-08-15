class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        // //使用辅助数组
        // //时间复杂度O(n^2) 空间复杂度O(n^2)
        // int n = matrix.size(); //行列数量相等
        // //vector<vector<int>> arr(n, vector<int>(n)); //辅助数组
        // auto arr = matrix;
        // //一行一行进行拷贝
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         arr[j][n - 1 - i] = matrix[i][j];
        //     }
        // }
        // //将原数组更新
        // // for (int i = 0; i < n; ++i)
        // // {
        // //     for (int j = 0; j < n; ++j)
        // //     {
        // //         matrix[i][j] = arr[i][j];
        // //     }
        // // }
        // //将原数组更新
        // // int i = 0;
        // // for (auto x : arr)
        // // {
        // //     matrix[i++] = x; 
        // // }  
        // matrix = arr;


        // //进行翻转数组
        // //时间复杂度O(n^2) 空间复杂度O(1)
        // int n = matrix.size();
        // //上下翻转
        // for (int i = 0; i < n / 2; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         swap(matrix[i][j], matrix[n - 1 - i][j]);
        //     }
        // }
        // //沿着主对角线翻转
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < i; ++j)
        //     {
        //         swap(matrix[i][j], matrix[j][i]);
        //     }
        // }


        //进行原地旋转
        //时间复杂度O(n^2) 空间复杂度O(1)
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j < (n + 1) / 2; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};