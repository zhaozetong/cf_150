#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int m;
    m = 10;
    // cin>>m;
    vector<int> temp(m+1);// 指定长度
    temp[0]=1;
    temp[1]=1;
    for(int i =2;i<m+1;i++)
    {
        temp[i] = temp[i-1]+temp[i-2];
    }
    cout<<temp[m]<<endl;
    for(auto i:temp)
    {
        cout<<i<<endl;
    }
    return 0;
}