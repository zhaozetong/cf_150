#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 注意：
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。

// 开头一致,结尾一致,如何最小化?nonono 
// 非最优:一次找一个,adddddbcaddd  -> abc Ma ? abc
///                 abcdddddddda
// 重点:只需要覆盖,不需要顺序一致
// 1,直到弄完再回溯
// 2,只要满足就尝试回溯
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char,int> map_t;
        unordered_map<char,int> map_s;
        for(char c:t)
        {
            map_t[c]+=1;
        }
        int left=0,right=0;
        int min_len=s.size()+1;
        int res_left =s.size()+1;
        int equal_num=0;

        while(right<s.size())
        {
            char c = s[right];
            map_s[c]+=1;
            if(map_t.find(c)!=map_t.end()&&map_s[c]==map_t[c])// 多加一层数量判断?
            {
                equal_num++;
            }
            if(equal_num==map_t.size())
            {
                if((right-left+1)<min_len) // 记录一整个
                {
                    min_len = right-left+1;
                    res_left = left;
                }
                while(equal_num==map_t.size())
                {
                    left++;
                    char c0 = s[left-1];
                    map_s[c0]-=1;
                    if(map_t.find(c0)!=map_t.end()&&map_s[c0]==(map_t[c0]-1))// 说明出了
                    {
                        equal_num--;
                        break;// 没必要
                    }
                }

                if((right-left+2)<min_len)
                {
                    min_len = right-left+2;
                    res_left = left-1;
                }

            }

            right++;
        }
        if(min_len==s.size()+1)
        {
            return "";
        }
        return s.substr(res_left,min_len);
        
    }
};
int main()
{
    string s1 = "bbaa";
    string s2 = "abcdsaddddddda";
    string t = "aba";
    Solution sol;
    cout<<sol.minWindow(s1,t)<<endl;
    cout<<sol.minWindow(s2,t)<<endl;
    return 0;
}   