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
                    cout << "4" << flag << endl;
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
                    cout << "4" << flag << endl;
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
                    cout << "4" << flag << endl;
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
                    cout << "4" << flag << endl;
                    return ;
                }
                count--;
                vis[x][y] = false;
            }
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();
        const char* str = word.c_str();
        vector<vector<bool>> vis(m, vector(n, false));
        vector<pair<int, int>> search;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) if (board[i][j] == str[0]) search.push_back({i, j});
        }      
        bool flag = false;
        for (auto& [x, y] : search)
        {
            backtrack(board, str, vis, flag, x, y, 0, 0);
        }
        return flag;
    }
};