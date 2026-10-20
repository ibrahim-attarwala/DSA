/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* root,int target,int curr){
        curr+=root->val;
        if(!root->left && !root->right){
            return curr==target;
        }
        if(!root->left){
            return f(root->right,target,curr);
        }
        if(!root->right){
            return f(root->left,target,curr);
        }
        return f(root->left,target,curr)||f(root->right,target,curr);
    }
    bool hasPathSum(TreeNode* root, int target) {
        if(!root)return false;
        return f(root,target,0);
    }
};