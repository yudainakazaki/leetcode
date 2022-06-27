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
        int buy = 0, sell = 1, res = 0;
        while(sell < prices.size()){
            if(prices[buy] < prices[sell]){
                res = max(res, prices[sell] - prices[buy]);
            }else{
                buy = sell;
            }
            sell++;
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> prices;
    int price;
    for(int i = 0; i < n; i++){
        cin >> price;
        prices.push_back(price);
    }
    
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}