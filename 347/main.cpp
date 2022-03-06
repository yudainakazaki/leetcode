#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

//time complexity is N + N + k -> O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        priority_queue<pair<int, int>> pq;

        for(int num:nums) m[num]++;

        for(auto item:m)
            pq.push(make_pair(item.second, item.first));

        vector<int> res;
        int count = 0;
        while(count < k){
            res.push_back(pq.top().second);
            pq.pop();
            count++; 
        }
        
        return res;

    }
};


int main() {
    int k = 2;
    vector<int> nums = {1,1,1,2,2,3};
    Solution solution;
    vector<int> res = solution.topKFrequent(nums, k);
    for(auto item:res){
        cout << item << endl;
    }    
}