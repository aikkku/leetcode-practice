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
    TreeNode* findMinNextNode(TreeNode* root) {
        while(root and root->left) {
            root = root->left;
        }

        return root;
    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else {
            if(!root->right) return root->left;
            if(!root->left) return root->right;
            TreeNode* minNode = findMinNextNode(root -> right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);
        }

        return root;
    }
};