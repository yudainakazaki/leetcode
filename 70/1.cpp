#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

//space complexity: O(1)
//time complexity: O(N)

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int oneBefore = 2, twoBefore = 1, total;
        for(int i = 3; i <= n; i++){
            total = oneBefore + twoBefore;
            twoBefore = oneBefore;
            oneBefore = total;
        }
        return total;
    }
};

// we define null as INT_MIN in this program

int main(){
    int n;
    cin >> n;
    Solution solution;
    cout << solution.climbStairs(n) << endl;
    return 0;
}