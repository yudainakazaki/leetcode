#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    int size;
    KthLargest(int k, vector<int>& nums) { 
        size=k;
        for(auto c:nums)
        {
            q.push(c);
            if(q.size() > k) q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > size) q.pop();
        return q.top();
    }
};


int main() {
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(k, nums);
    cout << obj->q.top() << endl;
    // cout << obj->add(3) << endl;
    // cout << obj->add(10) << endl;
    // cout << obj->add(9) << endl;
    // cout << obj->add(4) << endl;
    // cout << obj->add(5) << endl;
}