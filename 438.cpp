#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        // 直接映射
        vector<int> res;
        if(p.size()>s.size())
            return res;
        unordered_map<char,int> p_map;
        unordered_map<char,int> s_map;
        for (int i = 0; i < p.size(); i++)
        {
            p_map[p[i]] += 1;
        }   
        // 每次都比较
        for (int i=0;i<p.size()-1;i++)
        {
            s_map[s[i]] += 1;// 构建初始
        }
        for(int i=0;i+p.size()-1<s.size();i++)
        {
            if(i!=0)// 移除第一个
            {
                s_map[s[i-1]] -= 1;// 构建初始
            }
            s_map[s[i+p.size()-1]] += 1;
            int label = 1;
            for(const auto&pair:p_map)
            {
                if(s_map[pair.first]!=pair.second)//有一个不行就直接break出去
                {
                    label=0;
                    break;
                }
                    
            }
            if(label==1)
                res.push_back(i);
            
        }
        return res;
    }
};