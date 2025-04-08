#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // 还是利用红黑树吧
        vector<int> res;
        map<int,int> rb;

        for (int i = 0; i < k; i++)
        {
            rb[nums[i]] +=1;
        }
        res.push_back(rb.rbegin()->first);
        for (int i = k; i < nums.size(); i++)
        {
            rb[nums[i]] +=1;
            if(rb[nums[i-k]]==1)
            {
                rb.erase(nums[i-k]);
            }
            else
            {
                rb[nums[i-k]] -=1;
            }
            res.push_back(rb.rbegin()->first);
             
        }
        return res;
        
    }
};

class Solution {// 利用deque，维护递减队列?
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> dq; // 存储元素索引，保持单调递减
            vector<int> res;
    
            for (int i = 0; i < nums.size(); ++i) {
                // Step 1: 移除过期索引（不在窗口中的）
                if (!dq.empty() && dq.front() <= i - k) {
                    dq.pop_front();
                }
    
                // Step 2: 保持单调递减队列，移除所有比当前元素小的
                while (!dq.empty() && nums[dq.back()] < nums[i]) {
                    dq.pop_back();
                }
    
                // Step 3: 当前元素入队
                dq.push_back(i);
    
                // Step 4: 记录当前窗口的最大值（窗口形成后）
                if (i >= k - 1) {
                    res.push_back(nums[dq.front()]);
                }
            }
    
            return res;
        }
    };
    