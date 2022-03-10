#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    priority_queue<int, vector<int>, greater<int>> pq;

    void getDepth(TreeNode* node, int count){
        if(!node) return;
        count++;
        if(!node->left and !node->right)
            pq.push(count);
    
        getDepth(node->left, count);
        getDepth(node->right, count);
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left and !root->right) return 1;
        getDepth(root->left, 1);
        getDepth(root->right, 1);
        return pq.top();
    }
};


int main(){

}