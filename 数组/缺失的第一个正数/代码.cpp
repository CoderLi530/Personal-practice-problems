class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        // //1. 使用哈希表进行查找
        // //时间复杂度O(n) 空间复杂度O(n)
        // unordered_set<int> us;
        // for (auto x : nums) us.insert(x);
        // for (int i = 1; i < INT_MAX; ++i)
        // {
        //     if (!us.count(i)) return i;
        // }
        // return -1;


        // //2. 先对数组进行排序，然后让标志位等于1，遍历数组找到最小的正整数
        // //时间复杂度O(nlogn) 空间复杂度O(1)
        // //进行排序
        // sort(nums.begin(), nums.end());
        // int flag = 1;
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     //为负数flag不需要变
        //     if (nums[i] <= 0);
        //     //相等说明flag不是没有出现的最小正整数，flag++
        //     else if (nums[i] == flag) flag++;
        //     //当前的数大于flag说明flag就是最小的
        //     else if (nums[i] > flag) return flag;
        //     //nums[i] < flag不需要变化
        //     else ;
        // }
        // return flag;


        // //3. 对哈希表的优化：不用哈希表，在原数组进行修改
        // //时间复杂度O(n) 空间复杂度O(1)
        // //答案一定是在[1, n + 1]中
        // //(1. 对负数和0修改成n+1
        // //(2. 对遍历的数进行判断：在[1, n]中，对应（下标 - 1）加上负号
        // //(3. 之后遍历数组，数组全负则答案为n+1，否则返回值+1
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     if (nums[i] <= 0) nums[i] = nums.size() + 1;
        // }
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     //对遍历的数进行取绝对值
        //     int tmp = abs(nums[i]);
        //     //已经是负数就不需要变化
        //     if (tmp <= nums.size()) nums[tmp - 1] =  -abs(nums[tmp - 1]);
        // }
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     if (nums[i] > 0) return i + 1;
        // }
        // return nums.size() + 1;


        //4. 将数组恢复成原来的数组，nums[i]在[1, n]，将nums[i]放在nums[i] - 1位置
        //时间复杂度O(n) 空间复杂度O(1)
        //例如：[3, 4, -1, 1] --> [1, -1, 3, 4]
        //恢复完数组后遍历数组，遇到nums[i] != i + 1说明找到了缺失的正数
        for (int i = 0; i < nums.size(); ++i)
        {
            //当nums[i] == nums[nums[i] - 1]时不需要交换
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        //遍历数组，遇到不等于i + 1时返回
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1) return i + 1;
        }
        //走到这里说明数组是[1, 2, 3, ... , n]，返回n + 1
        return nums.size() + 1;
    }
};