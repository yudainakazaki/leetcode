#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

//nums = 0,1,2,4,5,7
//curBeg:^
//curEnd:^

//time complexity = O(N)
//space complexty = O(N)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        vector<string> res;
        for(int i = 0; i < size;){
            int begin = i, end = i;
            while(end+1 < size and nums[end+1] == nums[end]+1) end++;
            if(end > begin) res.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
            else res.push_back(to_string(nums[begin]));
            i = end + 1;
        }
        return res;
    }
};

int main(){

    vector<int> nums = {0,2,3,4,6,8,9};
    Solution solution;
    vector<string> res = solution.summaryRanges(nums);

    for(auto item:res){
        cout << item << endl;
    }

    return 0;
}
