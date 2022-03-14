#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat[0].size();
        int m = mat.size();
        int res = 0 , countRow, countCol, index;
        for(int i = 0; i < m; i++){
            countRow = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1) {
                    countRow++;
                    if(countRow > 1) break;
                    index = j;
                }
            }
            if(countRow == 1){
                countCol = 0;
                for(int k = 0; k < m; k++)
                    if(mat[k][index] == 1) {
                        countCol++;
                        if(countCol > 1) break;
                    }
                if(countCol == 1) res++;
            }
        }
        return res;
    }
};

int main(){

    int n, m, num;

    cin >> m;
    cin >> n; 

    vector<vector<int>> mat;
    for(int i = 0; i < m; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            cin >> num;
            temp.push_back(num);
        }
        mat.push_back(temp);
    }

    Solution solution;
    int res = solution.numSpecial(mat);

    cout << res << endl;

    return 0;
}
