#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

//Time complexity = O(N)
//Space Complexity = O(N)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = 1;
        int sum = 0;
        int res = 0;
        for(auto n:nums){
            sum += n;
            if(m.find(sum-k) != m.end())
                res += m[sum-k];
            m[sum]++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3};
    int k = 3;
    int res = solution.subarraySum(nums, k);
    cout << res << endl;
}


//  1  1  1
//  LR
//  L  R