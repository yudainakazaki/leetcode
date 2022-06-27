#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> set;
		int i = 0, j = 0, n = s.size(), ans = 0;
		while( i<n && j<n){
			if(set.find(s[j]) == set.end()){ 
				set.insert(s[j++]);
				ans = max(ans, j-i);
			}else set.erase(s[i++]); 
		}
		return ans;
	}
};
// we define null as INT_MIN in this program

int main(){
    string s;
    cin >> s;
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}