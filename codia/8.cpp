#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
    int len;
    cin>>len;
    vector<int> vec={1,2,2};
    int j=2;
    for(int i=2;i<len;i++)
    {
        if(vec[i]==1)
        {
            vec.push_back(vec[j]%2+1);
            j++;
        }
        else
        {
            vec.push_back(vec[j]%2+1);
            vec.push_back(vec[j]%2+1);
            j+=2;
        }
    }
    int res=0;
    for(int i=0;i<len;i++)
    {
        if(vec[i]==1)res++;
    }
    cout<<res<<endl;

    return 0;
}
