#include <iostream>
#include <list>
//     输入格式
// 第一行：两个整数N,M (0< N,M < 30,000,000) ，表示开始人数N和报数到M。
using namespace std;

int main()
{
    int n;
    long long m,k;
    cin>>n>>m;
    k=0;
    for(int i=1;i<=n;i++)
    {
        k = (k+m)%i;

    }
    cout <<k+1<<endl;
    return k+1;

}
