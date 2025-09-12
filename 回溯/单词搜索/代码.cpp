class Solution
{
public:

    void backtrack(vector<vector<char>>& board, const char* str, vector<vector<bool>>& vis, bool& flag, int x, int y, int start, int count)
    {
        if (flag) return ;
        //上
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !flag && !vis[x][y])
        {
            if (board[x][y] == str[start]) 
            {
                count++;
                vis[x][y] = true;
                backtrack(board, str, vis, flag, x - 1, y, start + 1, count);
                if (count == strlen(str))
                {
                    flag = true;
                    return ;
                }
                count--;
                vis[x][y] = false;
            }
        }
        //下
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !flag && !vis[x][y])
        {
            if (board[x][y] == str[start]) 
            {
                count++;
                vis[x][y] = true;
                backtrack(board, str, vis, flag, x + 1, y, start + 1, count);
                if (count == strlen(str))
                {
                    flag = true;
                    return ;
                }
                count--;
                vis[x][y] = false;
            }
        }
        //左
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !flag && !vis[x][y])
        {
            if (board[x][y] == str[start]) 
            {
                count++;
                vis[x][y] = true;
                backtrack(board, str, vis, flag, x, y - 1, start + 1, count);
                if (count == strlen(str))
                {
                    flag = true;
                    return ;
                }
                count--;
                vis[x][y] = false;
            }
        }
        //右
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && !flag && !vis[x][y])
        {
            if (board[x][y] == str[start]) 
            {
                count++;
                vis[x][y] = true;
                backtrack(board, str, vis, flag, x, y + 1, start + 1, count);
                if (count == strlen(str))
                {
                    flag = true;
                    return ;
                }
                count--;
                vis[x][y] = false;
            }
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        //回溯

        int m = board.size(), n = board[0].size(); //行列
        const char* str = word.c_str(); //字符串
        vector<vector<bool>> vis(m, vector(n, false)); //标记数组
        vector<pair<int, int>> search; //记录word中第一个字母在board出现位置的下标
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) if (board[i][j] == str[0]) search.push_back({i, j});
        }      
        bool flag = false; //标记位
        for (auto& [x, y] : search)
        {
            backtrack(board, str, vis, flag, x, y, 0, 0);
        }
        return flag;
    }
};


//优化后
class Solution 
{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool flag = false;

    void backtrack(vector<vector<char>>& board, const char* str, vector<vector<bool>>& vis, int x, int y, int len, int start)
    {
        if (flag) return ;
        //匹配完成，设置flag并进行返回
        if (start == len) 
        {
            flag = true;
            return ;
        }
        //走不同方向
        for (int i = 0; i < 4; ++i)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size() && !flag && !vis[a][b] && board[a][b] == str[start])
            {
                //标记该位置已访问，不走重复的分支
                vis[a][b] = true;
                backtrack(board, str, vis, a, b, len, start + 1);
                vis[a][b] = false;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
        //回溯
        //时间复杂度O(M*N*3^L) L为字符串的长度 空间复杂度O(MN)
        int m = board.size(), n = board[0].size(); //
        const char* str = word.c_str();
        vector<vector<bool>> vis(m, vector(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //从字符串开始位置进行回溯
                if (board[i][j] == str[0])
                {
                    //标记位置已访问，防止重复
                    vis[i][j] = true;
                    backtrack(board, str, vis, i, j, strlen(str), 1);
                    vis[i][j] = false;
                    //进行剪枝
                    if (flag) return flag;
                } 
            } 
        }
        return flag;
    }
};