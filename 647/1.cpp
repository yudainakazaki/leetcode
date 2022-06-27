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
    int countSubstrings(string s) {
        int count = 0;
        //for odd 
        for(int i = 0; i < s.size(); i++){
            count++;
            int l = i-1, r = i+1;
            while(l >= 0 and r <= s.size()-1 and s[l] == s[r]){
                count++;
                l--;
                r++;
            }            
        }
        //for even
        for(int i = 0; i <= s.size(); i++){
            int l = i, r = i+1;
            while(l >= 0 and r <= s.size() and s[l] == s[r]){
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};

int main(){
    string s;
    cin >> s;

    Solution solution;
    cout << solution.countSubstrings(s) << endl;

}