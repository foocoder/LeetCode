// ---- Program Info Start----
//FileName:     TwoSum.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-11 10:42:31
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum0(vector<int>& nums, int target) {//暴力法，O(n2)
        vector<int> indices;
        int lenOfNums = nums.size();

        for(int i=0; i<lenOfNums; i++){
            for(int j=i; j<lenOfNums; j++){
                if(nums[i]+nums[j] == target){
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
        return indices;
    }

    vector<int> twoSum(vector<int>& nums, int target) {//Hash Table, O(n) time , O(n)Space
        vector<int> indices;
        map<int, int> HashTable;
        int lenOfNums = nums.size();

        for(int i=0; i<lenOfNums; i++){
            HashTable[nums[i]] = i;
        }
        for(int i=0; i<lenOfNums; i++){
            const int gap = target - nums[i];
            if(HashTable.find(gap) != HashTable.end() && HashTable[gap] > i) {
                indices.push_back(i);
                indices.push_back(HashTable[gap]);
                break;
            }
        }
        return indices;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    //nums.push_back(15);
    Solution test;
    vector <int> indices = test.twoSum(nums, 6);
    cout<<indices[0]<<"--"<<indices[1]<<endl;
    return 0;
}
