#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto e : emails){ //N
            string mail="";
            for(char c : e){ //E
                if(c=='+' or c=='@') break;
                if(c=='.') continue;
                mail+=c;
            }
            mail+=e.substr(e.find('@'));
            s.insert(mail);
        }
        return s.size();
    }
};

int main() {
    vector<string> nums1 = {"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
    Solution solution;
    int res = solution.numUniqueEmails(nums1);
    cout << res << endl;
}