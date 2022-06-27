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
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> v(n, vector<int>(m));
        
        v[0][0] = 1;
        
        int i, j;
        
        for (i = 0; i < n; i++)
            v[i][0] = 1;
        
        for (j = 0; j < m; j++)
            v[0][j] = 1;
        
        for (i = 1; i < n; i++) {
            for (j = 1; j < m; j++) {
                v[i][j] = v[i-1][j] + v[i][j-1];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        
        return v[n-1][m-1];
    }
};

int main(){
    Solution solution;
    cout << solution.uniquePaths(3, 2) << endl;
    return 0;
}