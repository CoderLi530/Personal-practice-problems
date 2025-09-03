class Solution
{
public:

    void dfs(int num)
    {
        for ()
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // //bfs
        // //时间复杂度O(M+N) 空间复杂度O(M+N)
        // //拓扑排序解决有向无环图
        // //使用邻接表存储依赖关系，使用数组存储入度值
        // unordered_map<int, vector<int>> edges;
        // vector<int> in(numCourses);
        // for (auto arr : prerequisites)
        // {
        //     edges[arr[0]].push_back(arr[1]); //存储依赖关系
        //     in[arr[1]]++; //存储入度值
        // }
        // //将入度值为0的下标存入队列中
        // queue<int> q;
        // for (int i = 0; i < numCourses; ++i)
        // {
        //     if (in[i] == 0) q.push(i);
        // }
        // //进行拓扑排序
        // while (!q.empty())
        // {
        //     int x = q.front();
        //     //更新依赖关系的入度值
        //     for (auto num : edges[x])
        //     {
        //         //入度值减一
        //         in[num]--;
        //         //入度值为0进入队列
        //         if (in[num] == 0) q.push(num);
        //     }
        //     q.pop();
        // }
        // //判断有没有环，入度值不为0说明有环
        // for (auto x : in)
        // {
        //     if(x) return false;  
        // } 
        // return true;
        


        //dfs
        unordered_map<int, vector<int>> edges;
        vector<int> in(numCourses);
        //记录
        for (auto arr : prerequisites)
        {
            edges[arr[0]].push_back(arr[1]);
            in[arr[1]]++;
        }
        for (int i = 0; i < numCourses; ++i)
        {
            dfs(i);
        }
    }
};