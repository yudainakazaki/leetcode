#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

//time complexity = O(N)
//space complexity = O(N)

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;

        int sum = 0;
        for(auto n:nums)
            if(n%2 == 0) sum += n;
        
        for(int i = 0; i < queries.size(); i++){
            int before = nums[queries[i][1]];
            int after = nums[queries[i][1]]+queries[i][0];
            if(before%2 == 0 and after%2 == 0){
                sum -= before;
                sum += after;
            }else if(before%2 == 0 and (after%2 == 1 or after%2 == -1)){
                sum -= before;
            }else if((before%2 == 1 or before%2 == -1) and after%2 == 0){
                sum += after;
            }
            nums[queries[i][1]] = after;
            res.push_back(sum);
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> v = {1,2,3,4};
    vector<vector<int>> q = {{1,0},{-3,1},{-4,0},{2,3}};
    vector<int> res = solution.sumEvenAfterQueries(v, q);
    for(auto n:res){
        cout << n << endl;
    }
}

// O(N*E) where N is the size of the elements in the list and E is the length of an element