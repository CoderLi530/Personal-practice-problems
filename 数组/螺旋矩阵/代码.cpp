class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        // //模拟
        // //时间复杂度O(m*n) 空间复杂度O(m*n)
        // //方向的转变数组
        // int dx[4] = {0, 1, 0, -1};
        // int dy[4] = {1, 0, -1, 0};
        // int m = matrix.size(), n = matrix[0].size(); //数组的行列大小
        // vector<vector<bool>> vis(m, vector<bool>(n)); //标记数组
        // int row = 0, col = 0;
        // int index = 0;
        // vector<int> ret;
        // //遍历数组元素个数
        // for (int i = 0; i < m * n; ++i)
        // {
        //     //加入元素
        //     ret.push_back(matrix[row][col]);
        //     vis[row][col] = true;

        //     //进行判断是否转向
        //     int nextRow = row + dx[index], nextCol = col + dy[index];
        //     //位置越界或者已经访问的位置进行转向
        //     if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || vis[nextRow][nextCol])
        //     {
        //         index = (index + 1) % 4;
        //     }

        //     //更新row和col的位置
        //     row += dx[index];
        //     col += dy[index];
        // }
        // return ret;


        //按层模拟
        //时间复杂度O(m*n) 空间复杂度O(m*n)
        vector<int> ret;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        //遍历的位置不能越界
        while (left <= right && top <= bottom)
        {
            //左->右
            for (int i = top; i <= right; ++i)
            {
                ret.push_back(matrix[top][i]);
            }
            ++top;

            //上->下
            for (int i = top; i <= bottom; ++i)
            {
                ret.push_back(matrix[i][right]);
            }
            --right;

            //右->左
            //注意：top和right的变化可能已经越界了，注意检查
            if (top <= bottom)
            {
                for (int i = right; i >= left; --i)
                {
                    ret.push_back(matrix[bottom][i]);
                }
            }
            --bottom;

            //下->上
            //这也是一样。当然最上面两个循环也可以加判断，但是没必要（修改的top没有影响）
            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                {
                    ret.push_back(matrix[i][left]);
                }
            }
            ++left;
        }
        return ret;
    }
};