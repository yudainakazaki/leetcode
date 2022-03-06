#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char &c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    stk.push(c);
                    break;
                case ')':
                    if (stk.empty() || stk.top() != '(') return false; else stk.pop();
                    break;
                case ']':
                    if (stk.empty() || stk.top() != '[') return false; else stk.pop();
                    break;
                case '}':
                    if (stk.empty() || stk.top() != '{') return false; else stk.pop();
                    break;
            }
        }
        return stk.empty();
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isValid(s) << endl;
    return 0;
}