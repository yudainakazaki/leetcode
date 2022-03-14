#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

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
    int countLeft = 0, countRight = 0;
    int getVal(TreeNode* node, int count){
        if(!node) return 0;
        count += node->val;
        return getVal(node->left, count)+getVal(node->right, count);
    }
    int findTilt(TreeNode* root) {
        return abs(getVal(root->right) - getVal(root->left));
    }
};

int main(){

    int n, m, num;

    Solution solution;
    int res = solution.numSpecial(mat);

    cout << res << endl;

    return 0;
}