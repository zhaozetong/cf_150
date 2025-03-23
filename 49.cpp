#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string,int> umap;
        vector<vector<string>> res;
        int nums=0;//总数
        for(string s:strs)
        {
            string s0 = s;
            sort(s.begin(),s.end());
            if(umap.find(s)==umap.end())//新的
            {
                umap[s] = nums;
                nums ++;
                res.push_back({s0});
            }
            else
            {
                res[umap[s]].push_back(s0);

            }
        }
        return res;
    }
};

int main()
{
    std::string s = "Hello World";
    int pos = s.find("World");    // 查找 "World" 的起始索引
    if (pos != std::string::npos) // 判断是否找到
        std::cout << "Found at: " << pos << std::endl;

    pos = s.rfind("o"); // 反向查找 'o'，返回最后一个 'o' 的索引
    cout << "find at" << pos << endl;
    std::string sub = s.substr(6, 5); // 提取从索引 6 开始的 5 个字符，结果是 "World"
    cout << sub << endl;
    cout << s << endl;

    s.replace(2, 4, "nihaoma"); // 直接替换掉
    cout << s << endl;


    return 0;
}