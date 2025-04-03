#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int p = 1e9+7;

int combination(int m,int n)//caculate C_n^m, m<n/2
{
    // (n 2)
    if(m==1)return n;
    if(m==0)return 1;
    if(n==m)return 1;

    return combination(m-1,n-1)+combination(m,n-1);
}

long long quick_power(int m)
{
    // return m^{p-2} mode p
    int temp = p-2;
    // temp = 4;
    
    long long t=m;// 暂时结果累计到t上
    long long res=1;
    while(temp>0)
    {
        if((temp%2) == 1)
        {
            res = (res*t) % p;//注入结果
            temp--;
        }
        t = (t*t) %p;
        temp /= 2;
    }
    return res;
    
}

long long  factorial(int n,int m)//m小
{
    long long res=1;
    long long prefix=1;
    long long suffix=1;
    for(int i=n+m;i>=(n+1);i--)
    {
        prefix = (prefix*i)%p;
    }
    for (int i = 1; i <= m; i++)
    {
        suffix = (suffix*i)%p;
    }
    res = (prefix*quick_power(suffix))%p;
    return res;
}

int main()
{
    int m,n,q;
    cin>>m>>n>>q;
    vector<long long > table;
    for(int i=0;i<q;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        table.push_back(factorial(abs(x2-x1),abs(y2-y1)));
    }
    for(auto t:table)
    {
        cout<<t<<endl;

    }
    return 0;
}