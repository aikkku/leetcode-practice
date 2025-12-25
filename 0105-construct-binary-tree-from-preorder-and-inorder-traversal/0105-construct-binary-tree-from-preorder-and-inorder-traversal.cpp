class Solution {
public:
//inorder.       preorder
//left.          middle
//middle.        left
//right.         right

    unordered_map<int, int> mp;
    int pidx = 0;

    TreeNode* build(vector<int>& preorder, int inL, int inR) {
        if(inL > inR or pidx > preorder.size()) return nullptr;

        TreeNode* root = new TreeNode(preorder[pidx++]);
        int mid = mp[root->val];

        root->left = build(preorder, inL, mid - 1);
        root->right = build(preorder, mid + 1, inR);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};
