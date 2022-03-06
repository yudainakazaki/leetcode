#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:

    typedef pair<int, vector<int>> Pair;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> res;
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        
        for(int i:nums1)
            for(int j:nums2)
                pq.push({i+j, {i, j}});

        while(res.size() < k and !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};


int main() {
    int k = 3;
    vector<int> nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    Solution solution;
    vector<vector<int>> res = solution.kSmallestPairs(nums1, nums2, k);
    for(auto item:res){
        cout << "[" << item[0] << "," << item[1] << "]" << endl;
    }    
}