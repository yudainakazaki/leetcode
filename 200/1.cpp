#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

//Time complexity = O(M*N)
//Space Complexity = O(1)

using namespace std;

class Solution {
public:

    void markIsland(vector<vector<char>>& grid, int i, int j){
        if(i < 0 or i > grid.size()-1 or j < 0 or j > grid[i].size()-1 or grid[i][j] != '1') return;
        grid[i][j] = '2';
        markIsland(grid, i-1, j);
        markIsland(grid, i+1, j);
        markIsland(grid, i, j-1);
        markIsland(grid, i, j+1);

        cout << "(" << i << "," << j << ") = " << grid[i][j] << endl;
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1') {
                    markIsland(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> grid = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
        };

    int res = solution.numIslands(grid);

    cout << res << endl;
    
    return 0;
}


