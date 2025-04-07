#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// （选做，不计分）某同学最近捡到了一个棋盘，他想在棋盘上摆放 K 个皇后。他想知道在他摆完这 K 个皇后之后，棋盘上还有多少个格子是不会被攻击到的。
// 注意：一个皇后会攻击到这个皇后所在的那一行，那一列，以及两条对角线。

// 输入描述：
// 第一行三个正整数 n,m,K，表示棋盘的行列，以及摆放的皇后的个数。
// 接下来 K 行，每行两个正整数 x,y，表示这个皇后被摆在了第 x 行，第 y 列，数据保证任何两个皇后都不会被摆在同一个格子里。
// 输出描述：
// 棋盘上不会被攻击到的格子数量

int main()
{
    int n,m,K;
    cin>>n>>m>>K;
    vector<pair<int,int>> queen;
    vector<vector<int>> borad(n,vector<int>(m,0));// 元素初始化
    for (int i = 0; i < K; i++)
    {
        int x,y;
        cin>>x>>y;
        queen.push_back(make_pair(x-1,y-1));
    }
    for(auto [x,y]:queen)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==x||j==y||abs(i-x)==abs(j-y))
                    borad[i][j] = 1;
            }
        }
    }
    int res = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!borad[i][j])
                res++;
        }
    }    
    cout<<res<<endl;

    return 0;
    
}