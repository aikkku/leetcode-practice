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
    TreeNode* minValueNode(TreeNode* root) {
        TreeNode* curr = root;
        while (curr && curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr ) return nullptr;

        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            TreeNode* minNode = minValueNode(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }

        return root;

    }
};