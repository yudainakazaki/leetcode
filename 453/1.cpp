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
    int minMoves(vector<int>& nums) {
        int minFiller = 0, maxVal = nums[0];
        int N = nums.size();

        if(N == 1) return 0;

        for(auto n:nums)
            maxVal = max(n, maxVal);
        
        for(auto n:nums)
            minFiller += maxVal - n;

        while(minFiller%(N-1) != 0)
            minFiller += N;

        return minFiller/(N-1);
    }
};

int main() {
    Solution solution;
    vector<int> v = {-100,0,100};
    int res = solution.minMoves(v);
    cout << res << endl;
}

// O(N*E) where N is the size of the elements in the list and E is the length of an element