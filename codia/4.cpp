#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int pp(int l,int r)
{
    int m = (r-l+1)%4;
    int res = (r-l+1)/4*3;
    int head = l%4;
    switch (m)
    {
    case 0 :
        /* code */
        return res;
        break;
    case 1:
        if(head==2)
            return res+1;
        else 
            return res;
        //0 1 0 0 0 1 0 0 0 1 0 0 0 1
        break;
    case 2:
        if(head==1||head==2)
            return res+1;
        else
            return res;
    default:
        if(head!=3)
            return res+1;
        else 
            return res;
        break;
    }
}
// 完美数
int main()
{
    // target = (a+b)*(a-b)--->分解之后，a,b都是整数
    // =2 mod(4),不行
    // 质数行  13 = 13*1 = 49-36
    // 其他的4*3-->2*6
    //cout<<sqrt(1e9)<<endl;
    int l,r;
    cin>>l>>r;
    cout<<pp(l,r)<<endl;
    return 0;
}

#include <iostream>
using namespace std;

int count_perfect_numbers(int l, int r) {
    // 计算 [l, r] 中非 2 (mod 4) 的数的个数
    int total = r - l + 1;
    // 计算 [l, r] 中 ≡ 2 (mod 4) 的数的个数
    int mod2_count = (r / 2 - (l - 1) / 2) - (r / 4 - (l - 1) / 4);
    return total - mod2_count;
}

int main() {
    int l, r;
    cin >> l >> r;
    cout << count_perfect_numbers(l, r) << endl;
    return 0;
}