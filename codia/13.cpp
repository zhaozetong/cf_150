// 在1 <= n < 256的整数中，打印所有其平方具有对称性质的数。如11*11=121
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool is_symmetry(int n)
{
    string s = to_string(n);
    string reversed_s = s;
    reverse(s.begin(),s.end());
    return s==reversed_s;
}

int main()
{
    // 思路1,手动计算出来,然后直接提交O(1)复杂度
    // 思路2,暴力算&&判断
    // a*a = a1en,
    vector<int>res;
    for (int i = 1; i < 256; i++)
    {
        int n=i*i;
        if(is_symmetry(n))
        {
            res.push_back(n);
            cout<<i<<",";
        }
    }
    cout<<endl;
    for(int i:res)
        cout<<i<<",";
    cout<<endl;
    return 0;
}