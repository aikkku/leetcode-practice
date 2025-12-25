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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null";

        queue<TreeNode*> q;
        string ans = "";

        q.push(root);

        while(!q.empty()) {
            int l = q.size();

            while(l--) {
                if(!q.front()) {
                    ans += "null,";
                    q.pop();
                } else {
                    TreeNode* temp = q.front();
                    q.pop();

                    q.push(temp->left);
                    q.push(temp->right);

                    ans+=to_string(temp->val) + ",";
                }
            }

        }

        return ans;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == 'n') return nullptr;
        vector<string> v;
        string temp = "";
        for(int i = 0; i < data.length(); i++) {
            if(data[i] == ',') {
                v.push_back(temp);
                temp = "";
            } else {
                temp += data[i];
            }
        }
        cout<<data;
        
        TreeNode* root = new TreeNode(stoi(v[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if(v[i][0] != 'n') {
                cur->left = new TreeNode(stoi(v[i]));
                q.push(cur->left);
            }

            i++;

            if(v[i][0] != 'n') {
                cur->right = new TreeNode(stoi(v[i]));
                q.push(cur->right);
            }

            i++;
        }
        
        return root;
    }
};
