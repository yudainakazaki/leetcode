#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

//Time complexity = O(M*N)
//Space Complexity = O(1)

class Solution {
private:
    int count = 0;
    void markIsland(vector<vector<int>>& grid, int i, int j){
        if(i < 0 or i > grid.size()-1 or j < 0 or j > grid[i].size()-1 or grid[i][j] != 1) return;
        grid[i][j] = 2;
        count++;
        markIsland(grid, i-1, j);
        markIsland(grid, i+1, j);
        markIsland(grid, i, j-1);
        markIsland(grid, i, j+1);

        cout << "(" << i << "," << j << ") = " << grid[i][j] << endl;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                count = 0;
                if(grid[i][j] == 1) {
                    markIsland(grid, i, j);
                    res = max(count, res);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    int res = solution.maxAreaOfIsland(grid);

    cout << res << endl;
    
    return 0;
}


