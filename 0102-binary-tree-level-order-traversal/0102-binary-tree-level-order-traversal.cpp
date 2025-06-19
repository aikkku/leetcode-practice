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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(root) q.push(root);

        while(!q.empty()) {
            vector<int> temp;

            int l = q.size();
            while(l--) {
                TreeNode* tt = q.front();
                temp.push_back(tt->val);
                q.pop();
                if(tt->left) q.push(tt->left);
                if(tt->right) q.push(tt->right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
