#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string getDomain(string str){
        for(int i = 0; i < str.size(); i++)
            if(str[i] == '.') return str.substr(i+1);
        return str;
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> m;
        vector<string> res;

        for(auto s:cpdomains){
            int count = stoi(s.substr(0, s.find(" ")));
            string domain = s.substr(s.find(" ")+1);
            while(true){
                m[domain] += count;
                string temp = getDomain(domain);
                if(domain == temp) break;
                else domain = temp;
            }
        }

        for(auto item:m)
            res.push_back(to_string(item.second) + " " + item.first);

        return res;
    }
};

int main(){

    vector<string> s = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};

    Solution solution;
    vector<string> res = solution.subdomainVisits(s);

    for(auto s:res){
        cout << s << endl;
    }

    return 0;
}
