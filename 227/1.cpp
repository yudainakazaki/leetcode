#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        int stackTop = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) 
                currentNumber = currentNumber*10 + stoi(&currentChar);
            if (!isdigit(currentChar) and !iswspace(currentChar) or i == len - 1) {
                switch(operation) {
                    case '-':
                        stack.push(-currentNumber);
                        break;
                    case '+':
                        stack.push(currentNumber);
                        break;
                    case '*':
                        stackTop = stack.top();
                        stack.pop();
                        stack.push(stackTop * currentNumber);
                        break;
                    case '/':
                        stackTop = stack.top();
                        stack.pop();
                        stack.push(stackTop / currentNumber);
                        break;
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};


int main() {
    Solution solution;
    string s = "3+2*2";
    int res = solution.calculate(s);
    cout << res << endl;
}