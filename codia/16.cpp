#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
// 题目描述
// 贝茜把N (1 <= N <= 80)粒蓝色和橙色的珠子连成了一串，问有多少对珠子（相邻的）是不同颜色的。 
// 输入描述
// 第一行，一个整数N； 
// 第二行，N个数字（0或1），其中0表示橙色，1表示蓝色。
// 输出描述
// 输出相邻两粒珠是不同颜色的对数
int main()
{
    int res=0;
    int n;
    int last=0,next;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>next;
        if(next!=last&&i!=0)
            res++;
        last = next;
    }
    cout<<res<<endl;
    return 0;
    
}