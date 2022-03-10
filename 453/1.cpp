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
//Space Complexity = O(1)

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minFiller = 0, minVal = nums[0];
        int N = nums.size();

        if(N <= 1) return 0;

        for(auto n:nums) //N
            minVal = min(n, minVal);
        
        for(auto n:nums) //N
            minFiller += n - minVal;

        return minFiller;
    }
};

int main() {
    Solution solution;
    vector<int> v = {-100,0,100};
    int res = solution.minMoves(v);
    cout << res << endl;
}