#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)// 盛水最多
    {
        // 暴力---timeout
        int max_res=0;
        // for(int i=0;i<height.size()-1;i++)
        // {
        //     int temp_height = 0;
        //     for(int j=height.size()-1;j>i;j--)
        //     // for(int j=i+1;j<height.size();j++)
        //     {
        //         if(height[j]>temp_height)
        //         {                    
        //             int temp_size = (j-i)*min(height[i],height[j]);
        //             if(temp_size>max_res)
        //             {
        //                 max_res = temp_size;
        //                 temp_height = height[j];
        //             }
        //         }
        //     }
        // }
        int i=0,j=height.size()-1;
        int temp_res = 0;
        while(1)
        {
            temp_res=(j-i)*min(height[i],height[j]);
            max_res=max(max_res,temp_res);
            if(i+1==j)break;
            if(height[i]>height[j])
                j--;
            else   
                i++;
        }
        return max_res;  


    }
};