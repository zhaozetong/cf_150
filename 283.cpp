#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)// 0移动到队尾
    {
        int n = 0;// 非0 元素的数量
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[n] = nums[i];
                n++;
            }
        }
        if(n==nums.size())return ;
        for(int i=n;i<nums.size();i++)
        {
            nums[i] =0;
        }
    }
};