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

//Time complexity = O(logN)
//Space Complexity = O(N)

class Solution {
    private:
    int getDepth(TreeNode* node, int count){
        if(!node) return count;
        count++;
        return max(getDepth(node->left, count), getDepth(node->right, count));
    }
    public:
    int maxDepth(TreeNode* node){
        if(!node) return 0;
        return max(getDepth(node->left, 1), getDepth(node->right, 1));
    }
};

int main(){

}