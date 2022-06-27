#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        string num1str = "", num2str = "";

        while(l1 != nullptr){
            num1str = to_string(l1->val)+num1str;
            l1 = l1->next;
        }
        
        while(l2 != nullptr){
            num2str = to_string(l2->val)+num2str;
            l2 = l2->next;
        }

        int num1 = stoi(num1str);
        int num2 = stoi(num2str);
        int resNum = num1 + num2;

        string resNumStr = to_string(resNum);
        ListNode* res = new ListNode();
        ListNode* temp = res;
        for(int i = resNumStr.size()-1; i >= 1; i--){
            temp->val = resNumStr[i]-48;
            temp->next = new ListNode();
            temp = temp->next;
        }
        temp->val = resNumStr[0]-48;
        return res;
    }
};

void printNodes(ListNode* node){
    while(node != NULL){
        cout << node->val << endl;
        node = node->next;
    }
}

int main(){ 
    ListNode* node1 = new ListNode(2);
    node1->next = new ListNode(4);
    node1->next->next = new ListNode(3);
    // printNodes(node1);

    ListNode* node2 = new ListNode(5);
    node2->next = new ListNode(6);
    node2->next->next = new ListNode(4);
    // printNodes(node2);

    Solution solution;
    ListNode* res = solution.addTwoNumbers(node1, node2);
    while(res != NULL){
        cout << res->val << endl;
        res = res->next;
    }
}