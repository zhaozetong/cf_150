#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

// 开关灯,数论问题.
// 只有是所有数字p1p2p3p4p5上面的幂次都是偶数才可以? 2 3 5
int main()
{
    int m;
    cin>>m;
    int temp=0;
    int k = floor(sqrt(m));
    
    for(int i=1;i<=k;i++)
    {
        cout<<i*i<<" ";
    }
    cout<<endl;
    // float f = 10.3;
    // int t = (int)f;(a1+1)(a2+1)(a3+1)要是奇数次,则要求,所有的都为偶数,自然为完全平方数

    // cout<<t<<endl;
    return 0;
}
