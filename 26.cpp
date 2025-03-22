#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;


class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            set<int> set1;
            int j=0;
            for(int i=0;i<nums.size();i++,j++)
            {
                int temp = nums[i];
                if(set1.count(temp)==1)
                {
                    j--;
                    continue;
                }
                else
                {
                    set1.insert(temp);
                    nums[j] = temp;
                }
            }
            if(j==nums.size()-1)return j+1;
            for(int i =j;i<nums.size();i++)
            {
                nums.pop_back();
            }
            return j+1;
        }
    };
int main() {
    std::unordered_map<int, std::string> umap;

    // 使用 insert 插入元素
    auto result = umap.insert({1, "apple"});
    if (result.second) {
        std::cout << "Inserted (1, apple)" << std::endl;
    } else {
        std::cout << "Failed to insert (1, apple)" << std::endl;
    }

    result = umap.insert({1, "orange"});  // 尝试插入键1，但键1已存在
    if (result.second) {
        std::cout << "Inserted (1, orange)" << std::endl;
    } else {
        std::cout << "Failed to insert (1, orange)" << std::endl;
    }

    return 0;
}