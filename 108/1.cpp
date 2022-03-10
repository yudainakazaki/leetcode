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

//-10 -3 0 5 9

class Solution {
public:
    TreeNode* makeBST(vector<int>& nums, int l, int r){
        if(r <= l) return NULL;
        int mid = (r+l)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = makeBST(nums, l, mid);
        node->right = makeBST(nums, mid+1, r);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return makeBST(nums, 0, nums.size());
    }
};

int main(){
    return 0;
}
