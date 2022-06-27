#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> lis;
        int curMax = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            lis[i] = 1;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] < nums[j]) {
                    lis[i] = max(lis[i], lis[j]+1);
                    curMax = max(curMax, lis[i]);
                }
            }
        }
        return curMax;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {7,7,7,7,7,7,7};
    int res = solution.lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}

