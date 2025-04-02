// 假设在一个

// XOY​​坐标的平面上，机器人一开始位于原点
// (0,0)，面向Y​轴正方向。 机器人可以执行向左转，向右转，向后转，前进四个指令。

// 指令为：
// −1 表示向左转
// 1 表示向右转
// 0 表示向后转
// 2​ 表示向前走一步
// 现在给你一个指令序列，求机器人最终的位置。
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;



int main()
{
    int x=0,y=0;
    // 利用模4的结果
    int n=0;
    // printf("%d\n",(-1%2));
    cin>>n;
    int direction = 0;// 初始向上,1向右
    int reverse = 1;// 不反转

    vector<int> path(n);
    for(int i=0;i<n;i++)
    {
        cin>>path[i];
    }
    for(auto it: path)
    {
        if(it==0)
            reverse *= -1;
        else if(it==1||it==-1)
        {
            int temp = it + direction;
            if(temp!=0||temp!=1)
                reverse *= -1;
            direction = (temp+2)%2;  // 0,-1'''-1
        }
        else//it == 2
        {
            if(direction==1)//right
                x+=reverse;
            else
                y+=reverse;
        }
        //printf("%d %d\n",direction,reverse);
    }
    printf("%d %d",x,y);
    
    return 0;
}