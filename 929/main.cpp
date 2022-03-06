#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

//traverse the list 
//apply a process to simplify it 
//count the num of unique email addresses using map

class Solution {
private:
    string simplify(string email){

        string local = email.substr(0, email.find("@"));
        string domain = email.substr(email.find("@"), email.size()-1);
        local.erase(remove(local.begin(), local.end(), '.'), local.end()); 
        for(int i = 0; i < local.size(); i++)
            if(local[i] == '+'){
                local = local.substr(0, i);
                break;
            }
        cout << local+domain << endl;
        return local+domain;
    }
    
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto e:emails) s.insert(simplify(e));
        return s.size();
    }
};

int main() {
    vector<string> nums1 = {"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
    Solution solution;
    int res = solution.numUniqueEmails(nums1);
    cout << res << endl;
}

// O(N*E) where N is the size of the elements in the list and E is the length of an element