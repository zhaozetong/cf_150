#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
// 在计算机科学领域，如何高效生成指定的序列是一个非常重要的问题。现在给你一个字符串，且这个字符串内部的字符已经升序有序。
// 请你找出由这些字符构成的所有的序列。

// 输入描述
// 输入的第一行是一个整数n，表示测试数据组数。

// 接下来n行，每行输入一个字符升序有序的字符串。字符串中只包含小写字母，长度不超过8。
// 输出描述
// 对于每组输入，输出由输入的字符串中的字符构成的所有序列，按字典序升序排列，结果中不能出现相同的序列。

// 每组输出后面跟一个空行。
vector<string> solution(string& s)
{
    vector<string> res;
    sort(s.begin(),s.end());// 保证有序
    do
    {
        for(char c:s)
        {
            cout<<c;
        }
        cout<<endl;
    }while(next_permutation(s.begin(),s.end()));

    return res;
}

int main() {
    int n;
    cin>>n;
    vector<string> ss;
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        ss.push_back(t);
    }
    for(auto it:ss)
    {
        solution(it);
        cout<<endl;
    }
    return 0;
}

