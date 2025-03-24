#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:// nums = [100,4,200,1,3,2]---> [1,2,3,4]
    int longestConsecutive(vector<int> &nums)// 动态规划
    {
        // 最长连续序列?
        // 筒排序后遍历？筒有点大了
        sort(nums.begin(),nums.end(),[](int a,int b){return a<b;});
        int max_len=0;
        int temp_len=0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(i==0)
            {
                temp_len++;
                continue;
            }
            if(nums[i]==nums[i-1]-1)
                temp_len++;
            else
            {
                max_len = max(max_len,temp_len);
            }
        }
        if(temp_len>max_len)max_len = temp_len;
        return temp_len;
    }
};

int longestConsecutive(vector<int> &nums)// 动态规划
{
    // 最长连续序列?
    // 筒排序后遍历？筒有点大了
    sort(nums.begin(),nums.end(),[](int a,int b){return a<b;});
    int max_len=0;
    int temp_len=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(i==0)
        {
            temp_len++;
            continue;
        }
        if(nums[i]==nums[i-1]+1)
            temp_len++;
        else if(nums[i]==nums[i-1]) continue;

        else
        {
            max_len = max(max_len,temp_len);
            temp_len=1;
        }
        cout<<temp_len<<endl;
    }
    if(temp_len>max_len)max_len = temp_len;
    return max_len;
}
int main()
{
    vector<int> temp = {3,2,4,5,10};
    cout<<longestConsecutive(temp)<<endl;
    return 0;

}