class Solution {
public:

    void solve(TreeNode* root, TreeNode*& templ) {
        if (root == nullptr) return;

        solve(root->right, templ);
        solve(root->left, templ);

        root->right = templ;
        root->left = nullptr;

        templ = root;
    }

    void flatten(TreeNode* root) {
        TreeNode* templ = nullptr;
        solve(root, templ);
    }
};