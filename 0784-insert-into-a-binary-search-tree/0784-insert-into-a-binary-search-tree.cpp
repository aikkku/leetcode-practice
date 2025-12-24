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

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        
        if(root->val == val) return root;
        else if(root->val > val) {
            if(root->left) {
                root->left = insertIntoBST(root->left, val);
                return root;
            } else {
                root->left = new TreeNode(val);
                return root;
            }
        } else {
            if(root->right) {
                root->right = insertIntoBST(root->right, val);
                return root;
            } else {
                root->right = new TreeNode(val);
                return root;
            }
        }
    }
};