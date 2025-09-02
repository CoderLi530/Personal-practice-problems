class Solution
{
public:

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int orangesRotting(vector<vector<int>> &grid)
    {
        //bfs
        //时间复杂度O(MN) 空间复杂度O(1)
        //多源路径扩散
        //从腐烂的橘子位置同时出发进行扩散
        int ret = 0; //腐烂的最小分钟
        int m = grid.size(), n = grid[0].size(); //行列数量
        bool flag = false; //腐烂是否扩散
        queue<pair<int, int>> q; //队列
        //将每个腐烂的橘子位置进入队列
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        while (!q.empty())
        {
            int count = q.size();
            while (count--)
            {
                auto num = q.front();
                //从四个方向进行腐烂扩散
                for (int k = 0; k < 4; ++k)
                {
                    int x = num.first + dx[k];
                    int y = num.second + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                    {   
                        q.push({x, y});
                        grid[x][y] = 2;
                        flag = true;
                    }
                }
                q.pop();
            }
            //腐烂的橘子扩散了就记录次数
            if (flag)
            {
                ++ret;
                flag = false;
            }
        }
        //完好的橘子周围是0，返回-1
        for (auto arr : grid)
        {
            for (auto x : arr) if (x == 1) return -1;
        }
        return ret;
    }
};