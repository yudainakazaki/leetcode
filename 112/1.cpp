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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        targetSum -= root->val;
        if(!root->left and !root->right and targetSum == 0) return true;
        else return hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum);
    }
};

int main() {

}

//Best case = the tree is well balanced
//Time Complexity = O(log N)
//Worst case = the tree has one single leaf
//Time Complexity = O(N)