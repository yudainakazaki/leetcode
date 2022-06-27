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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(auto interval : intervals){
            if(merged.empty() or merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }else{
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

int main() {
    int n, num1, num2;
    vector<vector<int>> intervals;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num1;
        cin >> num2;
        intervals.push_back({num1, num2});
    }

    Solution solution;

    vector<vector<int>> res = solution.merge(intervals);

    for(auto vec:res){
        for(auto v:vec){
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}


