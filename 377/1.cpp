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
    int combinationSum4(vector<int>& nums, int target) {
        map<int, unsigned int> dp;
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            dp[i] = 0;
            for(int n:nums)
                if(i-n >= 0)
                    dp[i] += dp[i-n];
        }
        return dp[target];
    }
};

int main(){
    int target;
    vector<int> nums;
    int num;
    while(true){
        cin >> num;
        if(num == -1) break;
        nums.push_back(num);
    }

    cin >> target;
    
    Solution solution;
    cout << solution.combinationSum4(nums, target) << endl;

    
    return 0;
}