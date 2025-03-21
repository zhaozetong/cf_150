#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {// 合并2到1中
            vector<int> temp;
            int i=0,j=0;
            if(nums2.size()==0)return;

            while(i+j<=m+n-1) // 3, 3 -->4 
            {
                if(nums1[i]<nums2[j])
                {
                    temp.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    temp.push_back(nums2[j]);
                    j++;
                }
            }
            nums1 = temp;
        }
    };

// input :