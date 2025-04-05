#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

// 有1×n的一个长方形，用一个1×1、1×2和1×3的骨牌铺满方格。

// 例如当n=3时为1×3的方格。此时用1×1、1×2和1×3的骨牌铺满方格，共有四种铺法。


int main()
{
    int n;
    // cout<<pow(2,100)<<endl;
    cin>>n;
    vector<long long> vec(n+1);
    if(n==1)return 1;
    if(n==2)return 2;
    vec[0]=1;vec[1]=1;vec[2]=2;
    for(int i=3;i<=n;i++)
    {
        vec[i] = vec[i-1]+vec[i-2]+vec[i-3];
    }
    cout<<vec[n]<<endl;
    return 0;
}