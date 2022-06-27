#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

#define null INT_MIN

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *treeGen(vector<int> nums) {
    vector<TreeNode*> nodes;
    //create nodes
    for(int i = 0; i < nums.size(); i++){
        TreeNode *node;
        if(nums[i] == null){
            node = NULL;
        }else{
            node = new TreeNode(nums[i]);
        }
        nodes.push_back(node);
    }

    //generate a tree
    for(int i = 0; i <= nodes.size()/2-1; i++){
        nodes[i]->left = nodes[2*i+1];
        nodes[i]->right = nodes[2*i+2];
    }

    return nodes[0];
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root -> val > p -> val) && (root -> val > q -> val)) {
            return lowestCommonAncestor(root -> left, p, q);
        }else if ((root -> val < p -> val) && (root -> val < q -> val)) {
            return lowestCommonAncestor(root -> right, p, q);
        }else{
            return root;
        }
    }
};

int main(){
    vector<int> nums = {6,2,8,0,4,7,9,null,null,3,5};
    TreeNode *root = treeGen(nums);
    Solution solution;
    cout << solution.lowestCommonAncestor(root, 2, 8)->val << endl;
    return 0;
}