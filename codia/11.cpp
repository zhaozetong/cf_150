#include <iostream>
#include <vector>
#include<string>

using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>B[i];
    }    
    int res=0;
    for(int i=0;i<n;i++)
    {
        res+=A[i]*B[i];

    }
    cout<<res<<endl;
    
    
}