#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;

// 失败:
// 不看题目,不会用栈

// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的子数组的个数 。
// 子数组是数组中元素的连续非空序列。
// 示例 1：
// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：
// 输入：nums = [1,2,3], k = 3
// 输出：2
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int i,j;int p; // i-j维护小于等于k,包括j
        int temp_sum=0;
        int res=0;
        for(i=0,j=0;j<nums.size(),i<nums.size();i++)
        {
            if(j<i) 
                j=i;
            if(i==j)
                temp_sum =nums[i];
            else
                temp_sum -= nums[i-1];
            while(temp_sum<k&&j<nums.size()-1)
            {
                j++;
                temp_sum+=nums[j];
            }
            if(temp_sum==k)
                res++;
            cout<<temp_sum<<" "<<i<<" "<<endl;

        }
        return res;

    }
};

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> prefixSumCount;
            prefixSumCount[0] = 1; // 初始化前缀和为0出现1次，处理从头开始的子数组
            int sum = 0;
            int count = 0;
            for (int num : nums) {
                sum += num;
                if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                    count += prefixSumCount[sum - k];
                }
                prefixSumCount[sum]++;
            }
            return count;
        }
    };
    
int main()
{
    Solution slu;
    vector<int> vec = {1,2,3};
    int k=3;
    cout<<slu.subarraySum(vec,k)<<endl;
    return 0;
}