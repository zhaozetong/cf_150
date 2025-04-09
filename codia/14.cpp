#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

// 就是输出1的正方形

int test(int n, int m, int i, int j)
{
    // int n,m,i,j;
    int res;

    // cin>>n>>m>>i>>j;
    //
    // i--;j--;// index
    int depth = 0; // 0 quan:(mn)-(m-2)*(n-2)=2m+2n-4
    // 四象限 bianjie juli
    depth = min(min(i - 1, n - i), min(j - 1, m - j));
    int before = (m * n) - (m - 2 * depth) * (n - 2 * depth);
    int init_i = depth + 1;
    int init_j = depth + 1;
    int new_m = m - 2 * depth;
    int new_n = n - 2 * depth;
    if (i == init_i) // 右
    {
        res = before + j - init_j + 1;
    }
    else if (j == m-depth) // 下
    {
        res = before + new_m + i - init_i;
    }
    else if (i == n - depth) // 左
    {
        res = before + new_m + new_n-1  + (m-depth-j);
    }

    else // 上
    {
        res = before + new_m * 2 + new_n * 2 - 3 + (init_i - i); //(m*n)-(m-2*depth-2)*(n-2*depth-2)-(new_n-i);
    }
    return res;
}
void print_res(int n)
{
    int testn,testm;
    testn = n;
    testm = n;
    for (int i = 1; i <= testn; i++)
    {
        for (int j = 1; j <= testm; j++)
        {
            //printf("(%d:%d):", i, j);
            cout << test(testn, testm, i, j)<<' ';
        }
        cout << endl;
    }
}
int main()
{
    int n;
    vector<int>res;
    int num;
    while(cin>>num)
    {
        res.push_back(num);
    }
    // cin>>num;
    // for(i=0;i<num;i++)
    // {
    //     cin>>m;
    //     res.push_back(m);
    // }
    for(int it:res)
    {
        print_res(it);
    }

    return 0;
}