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
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            
            int target = -nums[i];
            int front = i+1, back = nums.size()-1;

            while(front < back){
                if(target < nums[front] + nums[back]) back--;
                else if(target > nums[front] + nums[back]) front++;
                else{
                    vector<int> tuple= {nums[i], nums[front], nums[back]};
                    res.push_back(tuple);
                    while(nums[front] == tuple[1] and front < back) front++;
                    while(nums[back] == tuple[2] and front < back) back--;
                }
            }

            while(i + 1 < nums.size() and nums[i+1] == nums[i]) i++;
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

    vector<vector<int>> res = solution.threeSum(nums);

    for(auto vec:res){
        for(auto v:vec){
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}


