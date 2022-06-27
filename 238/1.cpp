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
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = nums[0];
        vector<int> res;
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == 0) count++;
            else mul *= nums[i];
        }

        switch(count){
            case 0:
                for(int i = 0; i < nums.size(); i++){
                    res.push_back(mul/nums[i]);
                }
                break;
            case 1:
                for(int i = 0; i < nums.size(); i++){
                    if(nums[i] == 0) res.push_back(mul);
                    else res.push_back(0);
                }
                break;
            default:
                vector<int> v(nums.size(), 0);
                res = v;
        }

        return res;
    }
};

int main() {
    int n, num;
    vector<int> nums;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }

    Solution solution;

    vector<int> res = solution.productExceptSelf(nums);

    for(int i:res){
        cout << i << " " << endl;
    }
    
    return 0;
}


