#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

#define COUNT 10
#define null INT_MIN

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print2DUtil(TreeNode *root, int space){
    
    if (root == NULL) return;
 
    space += COUNT;
 
    print2DUtil(root->right, space);
 
    cout<<endl;
    for (int i = COUNT; i < space; i++) cout << " ";
    cout << root->val << "\n";
 
    print2DUtil(root->left, space);
}

void printTree(TreeNode *root){
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

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

    // printTree(nodes[0]);

    return nodes[0];
}

// we define null as INT_MIN in this program

int main(){
    vector<int> nums = {6,2,8,0,4,7,9,null,null,3,5};
    treeGen(nums);
    return 0;
}