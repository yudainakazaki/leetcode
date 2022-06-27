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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(auto c : coins)
                if(i - c >= 0) dp[i] = min(dp[i], dp[i-c]+1);
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(){

    int n, amount, coin;
    vector<int> coins;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> coin;
        coins.push_back(coin);
    }

    cin >> amount;

    Solution solution;
    cout << solution.coinChange(coins, amount) << endl;

    return 0;
}