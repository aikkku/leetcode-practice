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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        vector<vector<int>> v;

        if(root) q.push(root);

        while(!q.empty()) {
            vector<int> tv;
            int l = q.size();

            while(l--) {
                TreeNode* temp = q.front();

                tv.push_back(temp->val);
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            if(level%2) reverse(tv.begin(), tv.end());

            v.push_back(tv);

            level++;
        }

        return v;
    }
};