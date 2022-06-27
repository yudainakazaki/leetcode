#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

//Time complexity = O(M*N)
//Space Complexity = O(1)

using namespace std;

//Time complexity = O(N)
//Space complexity = O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0]; 
        int curMax = nums[0];
        for(int i = 1; i < nums.size(); i++){
            curSum = max(nums[i], nums[i]+curSum);
            curMax = max(curSum, curMax);
        }
        return curMax;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {-2,1,-3,4,-1,2,1,-5,4};

    int res = solution.maxSubArray(grid);

    cout << res << endl;
    
    return 0;
}


