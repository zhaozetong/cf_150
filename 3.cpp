#include <iostream>
#include <vector>
#include<string>

using namespace std;
class Solution
{
public:

    int lengthOfLongestSubstring(string s)
    {
        int max_len=0;
        int temp_len = 0;
        int temp_index = 0;
        int j=s.size();
        for (int i = s.size()-1; i >= 0;i--)
        {
            temp_index = s.substr(i).find(s[i],j-i);
            if(temp_index==-1)
            {
                temp_len++;
            }
            else
            {
                temp_len = temp_index;

            }
            max_len = max(max_len,temp_index);

        }
        return max_len;
    }
};
int lengthOfLongestSubstring(string s)
{
    if(s.size()==1)
        return 1;
    int max_len=0;
    int temp_len = 0;
    int temp_index = 0;
    int j=s.size();
    for (int i = s.size()-1; i >= 0;i--,j++)
    {
        temp_index = s.substr(i+1).find(s[i],j);
        if(temp_index==-1)
        {
            temp_len++;
        }
        else
        {
            temp_len = temp_index-i+1;
            j = temp_index;

        }
        // cout<<temp_index<<" ";
        max_len = max(max_len,temp_len);
    }
    //cout<<endl;
    return max_len;
}
int main()
{
    string s="nihnaomani";
    int t=(s+"8").find('8',1);//excellent
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}