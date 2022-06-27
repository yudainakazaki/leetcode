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
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum = max(nums[i], sum + nums[i]);
            res = max(res, sum);
        }
        return res;
    }
};

int main(){
    int n, num;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }
    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}