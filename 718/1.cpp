#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// num1 = 0, 1, 3
// num2 = 1, 3, 6

//   - 0 1 3
// - 0 0 0 0
// 1 0 0 1 0
// 3 0 0 0 2
// 6 0 0 0 0
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int matrix[m+1][n+1];
        memset(matrix, 0, sizeof(matrix));
        int maxVal = 0;
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(nums1[j-1] == nums2[i-1]){
                    matrix[i][j] = matrix[i-1][j-1] + 1;
                    maxVal = max(maxVal, matrix[i][j]);
                }
            }
        }
        return maxVal;
    }
};

int main(){

    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    Solution solution;
    int res = solution.findLength(nums1, nums2);

    cout << res << endl;

    return 0;
}
