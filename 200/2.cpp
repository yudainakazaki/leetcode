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

    void flipCells(vector<vector<char>>& grid, int i, int j){
        if(i < 0 or i >= grid.size() or 
            j < 0 or j >= grid[i].size() or 
            grid[i][j] != '1') return;
            
        grid[i][j] = '2';
        flipCells(grid, i, j-1);
        flipCells(grid, i, j+1);
        flipCells(grid, i-1, j);
        flipCells(grid, i+1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    flipCells(grid, i, j);
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


