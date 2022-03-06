#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode* node1 = new ListNode;
    ListNode* node2 = new ListNode;
    ListNode* node3 = new ListNode;
    ListNode* node4 = new ListNode;
    ListNode* node5 = new ListNode;

    node1->val = 1;
    node1->next = node2;

    node2->val = 1;
    node2->next = node3;

    node3->val = 2;
    node3->next = node4;

    node4->val = 3;
    node4->next = node5;

    node5->val = 3;
    node5->next = NULL;

    ListNode* cur_node = node1;
    while (cur_node) {
        printf("%d\n", cur_node->val);
        cur_node = cur_node->next;
    }

    Solution s;
    ListNode* res = s.deleteDuplicates(node1);
    cur_node = res;
    cout << "Result NodeList: " << endl;
    while (cur_node) {
        cout << cur_node->val << endl;
        cur_node = cur_node->next;
    }

    return 0;
}