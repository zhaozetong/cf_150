#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <tuple>
#include <unordered_set>

using namespace std;

namespace std {
    template <>
    struct hash<tuple<int, int, int>> {
        size_t operator()(const tuple<int, int, int>& t) const {
            size_t h1 = hash<int>{}(get<0>(t));
            size_t h2 = hash<int>{}(get<1>(t));
            size_t h3 = hash<int>{}(get<2>(t));
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };
}

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        unordered_set<tuple<int,int,int>> set;

        sort(nums.begin(), nums.end()); // 利用有序去解决
        bool found = binary_search(nums.begin(), nums.end(), 0);
        // if (found)
        //     res.push_back({0, 0, 0});

        for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            int k =0;//后续的数量 
            for (int j = nums.size() - 1; j > i && nums[j] >= 0; j--,k++)
            {
                int inverse = -(nums[i] + nums[j]);
                found = binary_search(nums.begin()+i+1, nums.end()-k-1, inverse);
                if (found)
                    //res.push_back({nums[i], nums[j], inverse});
                    set.insert(make_tuple(nums[i],inverse, nums[j]));

            }
        }
        if(set.size()==0)
        {
            res.push_back({});
            return res;
        }
        else
        {
            for(auto i : set)
            {
                res.push_back({get<0>(i),get<1>(i),get<2>(i)});
            }
        }
        return res;
    }
};
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    unordered_set<tuple<int,int,int>> set;

    sort(nums.begin(), nums.end()); // 利用有序去解决
    bool found = binary_search(nums.begin(), nums.end(), 0);
    // if (found)
    //     res.push_back({0, 0, 0});

    for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
    {
        int k =0;//后续的数量 
        for (int j = nums.size() - 1; j > i && nums[j] >= 0; j--,k++)
        {
            int inverse = -(nums[i] + nums[j]);
            found = binary_search(nums.begin()+i+1, nums.end()-k-1, inverse);
            // cout<<i<<j<<endl;
            // printf("%d %d ",i,j);
            // cout<<"nihao"<<endl;
            if (found)
                //res.push_back({nums[i], nums[j], inverse});
                set.insert(make_tuple(nums[i],inverse, nums[j]));

        }
    }
    if(set.size()==0)
    {
        res.push_back({});
        return res;
    }
    else
    {
        for(auto i : set)
        {
            res.push_back({get<0>(i),get<1>(i),get<2>(i)});
        }
    }
    return res;
}
int main()
{
    vector<int>nums = {0,0,0,0, 0};
    vector<vector<int>>res = threeSum(nums);
    for(auto it:res)
    {
        for(auto i:it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}