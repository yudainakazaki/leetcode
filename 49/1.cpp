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
//Space complexity = O(N)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m; //N
        for(auto str:strs){ //N times
            string temp = str;
            sort(temp.begin(), temp.end());
            m[temp].push_back(str);
        }

        vector<vector<string>> res;//N
        for(auto item:m) //average -> logN times, worst -> N times
            res.push_back(item.second);

        return res;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = solution.groupAnagrams(strs);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

