#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int max_len = 0;
            int j=0;
            for(int i =0;i<nums.size()-1;i++)
            {
                int count =1;
                
                for(j = i+1;j<nums.size();j++)
                {
                    if(nums[j]==nums[i])
                        count ++;
                    if(count >=3)break;

                }
                if(count>=3)
                {
                    int temp = nums[j];
                    for(int k=j;k<nums.size();k++)
                    {
                        if(nums[k]==temp)
                        {
                            nums.erase(nums.begin()+k);
                            k--;
                        }
                    }
                }
                else continue;
            }
            return nums.size();
        }
    };