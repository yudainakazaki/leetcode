#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // vector<int> list_val;
        // ListNode* cur_node = head;
        // while (cur_node) {
        //     list_val.push_back(cur_node->val);
        //     cur_node = cur_node->next;
        // }
        // cur_node = head;
        // while (cur_node) {
        //     cur_node->val = list_val.back();
        //     list_val.pop_back();
        //     cur_node = cur_node->next;
        // }
        // return head;
        ListNode *pre = nullptr, *next = nullptr; 
        while (head){
            next = head->next;      //save the current's next node 
            head->next = pre;       //let the current point to its previous one
            pre = head;             //save the current node as pre
            head = next;            //move to next node
        }
        return pre;     
    }
};

int main() {
    ListNode* node1 = new ListNode;
    ListNode* node2 = new ListNode;
    ListNode* node3 = new ListNode;
    ListNode* node4 = new ListNode;
    ListNode* node5 = new ListNode;

    node1->val = 11;
    node2->val = 23;
    node3->val = 13;
    node4->val = 4;
    node5->val = 66;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    Solution solution;
    ListNode* returnedList = solution.reverseList(node1);
    ListNode* cur = returnedList;
    while (cur) {
        cout << cur->val << endl;
        cur = cur->next;
    }

}