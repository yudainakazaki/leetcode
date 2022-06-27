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

    void track(vector<vector<int>>& heights, int i, int j, set<vector<int>>& s){
        
        if(s.find({i, j}) != s.end()) return;

        s.insert({i, j});

        int curHeight = heights[i][j];
        if(j+1 <= heights[i].size()-1 and heights[i][j+1] >= curHeight) track(heights, i, j+1, s);
        if(j-1 >= 0 and heights[i][j-1] >= curHeight) track(heights, i, j-1, s);
        if(i-1 >= 0 and heights[i-1][j] >= curHeight) track(heights, i-1, j, s);
        if(i+1 <= heights.size()-1 and heights[i+1][j] >= curHeight) track(heights, i+1, j, s);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        set<vector<int>> atl;
        set<vector<int>> pac;

        for(int i = 0; i < heights.size(); i++)
            pac.insert({i, 0});

        for(int j = 0; j < heights[0].size(); j++)
            pac.insert({0, j});    

        for(int i = 0; i < heights.size(); i++)
            atl.insert({i, (int)heights[0].size()-1});

        for(int j = 0; j < heights[0].size(); j++)
            atl.insert({(int)heights.size()-1, j});

        for(auto a:atl){
            int i = a[0], j = a[1];
            int curHeight = heights[i][j];
            if(j+1 <= heights[i].size()-1 and heights[i][j+1] >= curHeight) track(heights, i, j+1, atl);
            if(j-1 >= 0 and heights[i][j-1] >= curHeight) track(heights, i, j-1, atl);
            if(i-1 >= 0 and heights[i-1][j] >= curHeight) track(heights, i-1, j, atl);
            if(i+1 <= heights.size()-1 and heights[i+1][j] >= curHeight) track(heights, i+1, j, atl);
        }

        for(auto p:pac){
            int i = p[0], j = p[1];
            int curHeight = heights[i][j];
            if(j+1 <= heights[i].size()-1 and heights[i][j+1] >= curHeight) track(heights, i, j+1, pac);
            if(j-1 >= 0 and heights[i][j-1] >= curHeight) track(heights, i, j-1, pac);
            if(i-1 >= 0 and heights[i-1][j] >= curHeight) track(heights, i-1, j, pac);
            if(i+1 <= heights.size()-1 and heights[i+1][j] >= curHeight) track(heights, i+1, j, pac);
        }

        vector<vector<int>> res;
        for(auto a:atl)
            if(pac.find(a) != pac.end()) res.push_back(a);

        return res;
    }
};

int main(){
    int n, m, height;
    cin >> n >> m;
    vector<vector<int>> heights;
    for(int i = 0; i < n; i++){
        vector<int> inner;
        for(int j = 0; j < m; j++){
            cin >> height;
            inner.push_back(height);
        }
        heights.push_back(inner);
    }

    Solution solution;
    vector<vector<int>> res = solution.pacificAtlantic(heights);
    cout << "Ans --------------" << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i][0] << "," << res[i][1] << endl;
    }

}