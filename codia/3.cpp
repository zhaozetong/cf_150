#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

bool is_prime(int a)
{
    for(int i=2;i<ceil(sqrt(a));i++)
    {
        if((a % i)==0)
        {
            return false;
        }
    }
    return true;
}

bool is_prime(int i,const vector<int>&prime)
{
    
    for(int p:prime)
    {
        if(i==p)return true;
        
        if((i%p)==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int x,y;//x<y
    cin>>x>>y;
    // 暴力? 当然是
    const vector<int> prime ={2,3,5,7,9,11,13,17,19,23,25,29,31,37,41,
        43,47,49,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,
        121,127,131,137,139,149,151,157,163,167,169,173,179,181,191,
        193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,
        277,281,283,289,293,307,311,313,317};// 暴力打表
    int num = 0;//总数
    
    for(int i=x;i<=y;i++)
    {
        if(i==0||i==1)
            continue;
        if(is_prime(i,prime))
        {
            num++;
        }
    }
    cout<<num<<endl;
    return 0;
}   