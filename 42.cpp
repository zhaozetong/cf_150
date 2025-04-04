#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <tuple>
#include <unordered_set>
#include <numeric> // 导入 accumulate
using namespace std;

class Solution
{
public: // [0,1,0,2,1,0,1,3,2,1,2,1]1+4+1
    int sum(int m,int n ,vector<int> &height)
    {
        int res =0;
        for(int i = m+1;i<n;i++)
            res+= height[i];
        return res;
    }
    bool check(int i,vector<int> &height)
    {
        bool res = false;
        if(i==0)
        {
            if(height[i]>height[1])
                res = true;
        }
        else if (i==height.size()-1)
        {
            if(height[i-1]<height[i])
                res = true;
        }
        else
        {
            if(height[i-1]<height[i]&&height[i]>height[i+1])// 取上升边
                res = true;
        }
        return res;
    }
    int trap(vector<int> &height)// 找递减后递增的结构。
    {
        int res = 0;
        vector<int> indexs;
        int i,j;
        // 找到大于两边的height
        for(i =0;i<height.size();i++)
        {
            if(i==0)
            {
                if(height[i]>height[1])
                    indexs.push_back(0);
            }
            else if (i==height.size()-1)
            {
                if(height[i-1]<height[i])
                    indexs.push_back(i);
            }
            else
            {
                if(height[i-1]<height[i]&&height[i]>height[i+1])// 取上升边
                    indexs.push_back(i);
            }

        }
        // 检查,保证中间的也是符合要求的
        int label = 0;
        vector<int> index2;// 最终label

        for(int i=0;i<indexs.size();i++)
        {
            if(i==0)
            {
                index2.push_back(indexs[i]);
            }
            else if (i==indexs.size()-1)
            {
                index2.push_back(indexs[i]);
            }
            else
            {
                if(height[indexs[i-1]]<=height[indexs[i]]&&height[indexs[i]]>=height[indexs[i+1]])// 取上升边
                    index2.push_back(indexs[i]);
            }                
        }

        for(int i=0;i<index2.size()-1;i++)
        {
            int i1 = index2[i];int i2 = index2[i+1];
            res+= min(height[i1],height[i2])*(i2-i1-1) - sum(i1,i2,height);
        }
        return res;
    }
};