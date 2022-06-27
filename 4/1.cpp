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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};
// we define null as INT_MIN in this program

int main(){
    int n, amount;
    cin >> n;
    vector<int> coins;
    int coin;
    for(int i = 0; i < n; i++){
        cin >> coin;
        coins.push_back(coin);
    }

    cin >> amount;
    
    Solution solution;
    cout << solution.coinChange(coins, amount) << endl;
    return 0;
}