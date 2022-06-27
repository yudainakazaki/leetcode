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
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 1, curMax = 0;
        while(sell < prices.size()){
            if(prices[buy] < prices[sell]){
                curMax = max(curMax, prices[sell]-prices[buy]);
            }else{
                buy++;
            }
            sell++;
        }
        return curMax;
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7,1,5,3,6,4};
    int res = solution.maxProfit(prices);
    cout << res << endl;
    return 0;
}

