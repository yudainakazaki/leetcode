#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

//traverse the list 
//apply a process to simplify it 
//count the num of unique email addresses using map

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int,int>> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]].first++;
            m[s[i]].second = i;
        }

        int res = s.size();
        for(auto item:m){
            if(item.second.first == 1)
                res = min(item.second.second, res);
        }
        return res == s.size() ? -1 : res; 
    }
};

int main() {
    string s = "loveleetcode";
    Solution solution;
    int res = solution.firstUniqChar(s);
    cout << res << endl;
}

// O(N*E) where N is the size of the elements in the list and E is the length of an element