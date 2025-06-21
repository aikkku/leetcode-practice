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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        targetSum -= root->val;
        if(targetSum == 0 and (!root->right) and !root->left) {
            return true;
        } else {
            if(!root->right and !root->left) return false;
            if(!root->right) return hasPathSum(root->left, targetSum);
            if(!root->left) return hasPathSum(root->right, targetSum);
            return hasPathSum(root->left, targetSum) or hasPathSum(root->right, targetSum);
        }

    }
};