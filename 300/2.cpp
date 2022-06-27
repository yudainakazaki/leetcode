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
        int res = 1;
        map<int, int> dp;
        for(int i = nums.size()-1; i >= 0; i--){
            dp[i] = 1;
            for(int j = i+1; j <= nums.size()-1; j++){
                if(nums[i] < nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }
    
    Solution solution;
    cout << solution.lengthOfLIS(nums) << endl;
    return 0;
}