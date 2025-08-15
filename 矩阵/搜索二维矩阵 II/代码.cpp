class Solution 
{
public:

    //二分查找算法
    bool binarySearch(vector<int>& matrix, int target)
    {
        int n = matrix.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (matrix[mid] < target) left = mid + 1;
            else if (matrix[mid] > target) right = mid - 1;
            else return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        // //使用哈希表进行查找
        // //时间复杂度O(m*n) 空间复杂度O(m*n) -- 没通过，超时
        // unordered_map<int, int> hash;
        // int m = matrix.size(), n = matrix[0].size();
        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         hash[matrix[i][j]]++;
        //         if (hash.count(target)) return true;
        //     }
        // }
        // //没有找到target，返回false
        // return false;
    

        // //直接遍历数组
        // //时间复杂度O(m*n) 空间复杂度O(1)
        // int m = matrix.size(), n = matrix[0].size();
        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         if (matrix[i][j] == target) return true;
        //     }
        // }    
        // return false;
    
    
        // //二分查找 -- 每一行都是有序的，对每一行进行二分查找
        // //时间复杂度O(log(m*n)) 空间复杂度O(1)
        // int m = matrix.size();
        // for (int i = 0; i < m; ++i)
        // {
        //     bool ret = binarySearch(matrix[i], target);
        //     if (ret == true) return true;
        // }
        // //没有找到target，返回false
        // return false;


        //Z字形搜索 -- 从右上角进行搜索，每一次搜索去掉一行或一列
        //时间复杂度O(m + n) 空间复杂度O(1)
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0)
        {
            if (matrix[row][col] > target) --col;
            else if (matrix[row][col] < target) ++row;
            else return true;
        }
        //没有找到target
        return false;
    }
};