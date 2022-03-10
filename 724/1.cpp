#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

//Time complexity = O(N)
//Space Complexity = O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left = 0;
        for(int n:nums) sum += n; //N
        for(int i = 0; i < nums.size(); i++){ //N
            sum -= nums[i];
            if(left == sum) return i;
            left += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> v = {2,1,-1};
    int res = solution.pivotIndex(v);
    cout << res << endl;
}

// O(N*E) where N is the size of the elements in the list and E is the length of an element